/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Author: Pouya Mohammadi
 *
 */


#ifndef BASETASK_H
#define BASETASK_H

#include <Eigen/Core>

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

private:
};


#endif /* BASETASK_H */
