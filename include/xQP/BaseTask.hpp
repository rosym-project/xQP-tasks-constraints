/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Author: Pouya Mohammadi
 *
 */


#ifndef BASETASK_H
#define BASETASK_H

#include <Eigen/Core>
#include <string>
#include <KinDynModelFactory.hpp>

namespace xQP {
    enum HESSIAN_TYPE {
        IDENTITY,
        POSITIVE_DEFINITE,
        POSITIVE_SEMIDEFINITE,
        /* inspired by the OpenSoT
           HST_ZERO,                  // Hessian is zero matrix (i.e. LP formulation).
           HST_IDENTITY,              // Hessian is identity matrix.
           HST_POSDEF,                // Hessian is (strictly) positive definite.
           HST_POSDEF_NULLSPACE,      // Hessian is positive definite on null space of active bounds/constraints.
           HST_SEMIDEF,               // Hessian is positive semi-definite.
           HST_UNKNOWN                // Hessian type is unknown.
         */
    };
}


/**
 * @brief The BaseTask class
 * This is a pure abstract class that acts as an interface for a generic task.
 * Other tasks will extend this class.
 *
 * TODO right down the task
 */

class BaseTask {
public:
    BaseTask();
    virtual ~BaseTask();

    /**
     * @brief update updates the Jacobian et al. with current system state
     * @param q the system state (e.g., robot configuration)
     * @return True if all fine, false otherwise
     */
    virtual bool update(const Eigen::VectorXd & q) = 0;

    /** TODO Either update or compute cost function shoudl be private and
     * triggered by the other one...
     */

    /**
     * @brief compute_cost_function
     * @return True of all fine, flase otherwise
     * Computes the cost function that is the core of the QP problem. The
     * implementation depends on the nature of derived task.
     */
    virtual bool compute_cost_function() = 0;

    /**
     * @brief do_sanity_check
     * @return
     * This function performs sanity check on the inputs. E.g., checks the size
     * the size consistency of data (and more?)
     */
    virtual bool do_sanity_check() = 0;


    /**
     * @brief getConstraintMatrix
     * @return Constant reference to this->constraint_matrix
     */
    const Eigen::MatrixXd & getConstraintMatrix() const {
        return this->constraint_matrix;
    }

    /**
     * @brief getConstraintBounds
     * @return Constant reference to this->constraint_bounds
     */
    const Eigen::VectorXd & getConstraintBounds() const {
        return this->constraint_bounds;
    }

    /**
     * @brief getTaskSize
     * @return The task size, AKA, the number of rows of the Jacobian
     */
    int getTaskSize() {
        return this->task_size;
    }


protected:

    /**
     * @brief task_name An identifier for task
     */
    std::string task_name;

    /**
     * @brief J The Jacobian of the task
     * This is used to compute the Hessian matrix for the QP solver. For a
     * velocity task for instance, the sub class will use this to compute
     * J^T.J. Other task will use this accordingly.
     */
    Eigen::MatrixXd J;

    /**
     * @brief e The error of the task
     * This vector expresses the error function for a given task. For isntance,
     * in velocity control e=x_dot.
     */
    Eigen::VectorXd e;

    /**
     * @brief e_feedback The error feedback
     * Is a positive error feedback gain matrix.
     */
    Eigen::MatrixXd feedback_gain;

    /**
     * @brief constraint_matrix
     * This matrix together with constraint_bound define a ploytope which bound
     * the solution of Jq-e such that it is constraint_matrix*q<contraint_bound
     */
    Eigen::MatrixXd constraint_matrix;

    /**
     * @brief constraint_bounds
     * This vector together with constraint_matarix define a ploytope that bound
     * the solution of Jx-e such that it is constraint_matrix*q<contraint_bound
     */
    Eigen::VectorXd constraint_bounds;

    /**
     * @brief task_size The dimension of the task
     * AKA, the number of rows in the Jacobian matrix
     */
    int task_size;

    /**
     * @brief regularization_factor
     * Regularization factor to bound the solver output near singularities
     */
    double regularization_factor;

    /**
     * @brief is_floating_based
     * If the robot is floating based
     */
    bool is_floating_based = false;

    /**
     * @brief hessian_type
     * This class memeber describes the type of the hessian from the enum above.
     * This is an important class memeber as in certain cases, defining as correct
     * form will improve the performance (e.g., when it is identity)
     */
    int hessian_type;

    /**
     * @brief model
     * The kinematic chain/robot model that interfaces with the Kinematic/Dynamic
     * libraries and solvers. It is basically used to create for performing K/D
     * type of computations.
     * TODO decide how to clean this
     */
    KinDynModel * model;

    //TODO Note that the folating based criteria for the moment is not implemented
};


#endif /* BASETASK_H */
