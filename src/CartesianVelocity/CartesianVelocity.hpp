/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Author: Pouya Mohammadi
 *
 */


#ifndef CARTESIANVELOCITY_H
#define CARTESIANVELOCITY_H

#include <xQP/BaseTask.hpp>

class CartesianVelocity : public BaseTask
{
public:
    CartesianVelocity();
    CartesianVelocity(std::string name, int hessian);
    virtual ~CartesianVelocity();

    bool compute_cost_function() override;
    bool do_sanity_check() override;
    bool update(const Eigen::VectorXd &q) override;
};

// TODO implement floating based stuff


#endif /* CARTESIANVELOCITY_H */
