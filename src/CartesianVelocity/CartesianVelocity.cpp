/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Author: Pouya Mohammadi
 *
 */

#include "CartesianVelocity.hpp"

//CartesianVelocity::CartesianVelocity(std::string name, Eigen::VectorXd &home_conf, int hessian){
//    this->task_name = name;
//    this->hessian_type = hessian;
////    this->model = KinDynModelFactory::initialize()
//}

CartesianVelocity::CartesianVelocity(std::string name,
                                     int hessian,
                                     std::string urdf_path,
                                     std::string base_link,
                                     std::string ee_link,
                                     Eigen::VectorXd &home_conf,
                                     bool floating_base,
                                     bool parse_urdf_verbose,
                                     int kin_dyn_solver){
    this->task_name = name;
    this->hessian_type = hessian;
    this->model = KinDynModelFactory::initialize(urdf_path,
                                                 base_link,
                                                 ee_link,
                                                 floating_base,
                                                 parse_urdf_verbose,
                                                 kin_dyn_solver);

}

bool CartesianVelocity::update(const Eigen::VectorXd &q) {

}

bool CartesianVelocity::compute_cost_function() {


}
