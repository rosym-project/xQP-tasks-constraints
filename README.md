# xQP-tasks-constraints
The tasks and constraints that are the building blocks of a generic QP solver

This repository contains the code for individual tasks and constraints
that constitute a QP stack (e.g., iHQP). Each task or constraint will
compile into a single shared object (.so) that are loaded by the iHQP
solver. The rational for this decision is outlined later in this
readme.

## Dependencies 
For the moment:
1. Eigen3 (for linear algebra) [http://eigen.tuxfamily.org](http://eigen.tuxfamily.org)

## Motivation

### Goals
The implementation follows few goals:
1. Keep it light-weighted, easy to use, easy to deploy
2. Reduce the dependencies to bare minimum
3. Make it compliant and easy to adjust if the end user wants to use it
   - as a binary
   - in a component based system (e.g., OROCOS, Microblx, etc.)
   - by conforming to certain standards
4. In short, don't annoy the users!

### Reinventing the wheel
There are already many many qp based packages for robot control by
different research groups with exceptionally high quality
implementations. However, most of these works are rather tailored to
specific solver and/or theoretical approach. Special to this
implementation is OpenSoT by (mainly) [Enrico Mingo
Hoffman](https://github.com/EnricoMingo), [Alessio
Rocchi](https://github.com/arocchi) and [Arturo
Laurenzi](https://github.com/alaurenzi) from the Italian Institute of
Technology.

This work is heavily inspired by OpenSoT and its very nice structure.
However, for few reasons it tries to implement OpenSoT's idea in
different manner. Namely,
1. OpenSoT is highly coupled with several other packages that are not
   necessarily critical for the end users. This makes its usage on
   stand-alone applications rather cumbersome.
2. OpenSoT compiles its very rich collection of tasks and constraints
   into one binary. This implementation on the other hand goes for a
   different idea (more on this below)
3. While OpenSoT, its sibling projects (e.g., CartesI/O) and all its
   dependencies are available for free as a [debian
   package](https://github.com/ADVRHumanoids/XBotControl), for the
   time being it's not open source. Consequently, it is not so trivial
   to reshape and refactor it to make it compatible to specific
   requirements.
4. OpenSoT's configuration is rather exhausting and depends on an
   unhealthy number of yaml files. This is not OpenSoT's fault per se,
   rather due to its high number of dependencies and to number 1 in
   this list.

### On this implementation
Current work borrows the idea of task/constraint library from the
OpenSoT but compiles each of them into individual `.so` files. A
particular QP based solver/implementation then loads these
tasks/constraints on demand. Hence, the users are not forced to adopt
anything forced by us.

Such approach that mimics the component paradigm, grants some
conveniences. i) The code generation complexity for the `iHQP` solver
(or any other approach for that matter) will be reduced considerably;
ii) Stand-alone use of this library for the community is also
facilitated as we do not enforce any limitation on the end-users; iii)
Composability and reusability are alleviated; and iv) It facilitate
the conformity to particular standards, should the library is used for
specific projects.

## On RobMoSys
This project is being developed in the context of an ITP in RobMoSys
project. Consequently it should adhere to RobMoSys standards and it
should _conform_ to it. The code generation aspect shall be taken care
of in the iHQP implementation. As for the conformity, once it is
decided what it exactly means, a separate branch will be taking care
of it. It is my goal to keep the master branch as a generic,
stand-alone, ready to be used set of tasks and constraints.

## TODO
1. Give it a name!
2. In the spirit of code first, think later (!) I am adopting a
   structure that seems reasonable. However, the structure of the
   repository should be rethinked if necessary.
3. Consider suitable namespaces. It is my goal to limit the use of
   namespaces to the absolute necessary only. I do not wish to create
   eye sores for the users just so that I put my library name in front
   of their eyes.
4. Consistency check for calling them task or constraint. As it was
   said by [Kanoun et al.](https://ieeexplore.ieee.org/document/5766760) 
   _"To call these equations constraints or tasks is just a question of 
   context."_, however, it is necessary to be consistent regardless.
5. TBA
