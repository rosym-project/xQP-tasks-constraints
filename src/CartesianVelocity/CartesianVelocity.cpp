/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Author: Pouya Mohammadi
 *
 */

#include "CartesianVelocity.hpp"

CartesianVelocity::CartesianVelocity(std::string name, int hessian){
    this->task_name = name;
    this->hessian_type = hessian;
}

bool CartesianVelocity::update(const Eigen::VectorXd &q) {

}

bool CartesianVelocity::compute_cost_function() {


}
