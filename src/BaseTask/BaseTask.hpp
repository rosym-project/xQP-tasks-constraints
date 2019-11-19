/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Author: Pouya Mohammadi
 *
 */


#ifndef BASETASK_H
#define BASETASK_H

#include <Eigen/Core>
#include <string>

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

    /**
     * @brief compute_cost_function
     * @return True of all fine, flase otherwise
     * Computes the cost function that is the core of the QP problem. The
     * implementation depends on the nature of derived task.
     */
    virtual bool compute_cost_function() = 0;


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

    //TODO should the regularization factor be here?
    //TODO should the floating base boolean be declared here?

};


#endif /* BASETASK_H */
