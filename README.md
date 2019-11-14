# xQP-tasks-constraints
The tasks and constraints that are the building blocks of a generic QP solver

This repository contains the code for individual tasks and constraints
that constitute the iHQP. Each task or constraint will compile into a
single shared object (.so) that are loaded by the iHQP solver. The
rational for this decision is outlined later in this readme.

# Motivation

## Reinventing the wheel
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
   into one giant binary. This implementation on the other hand goes
   for a different idea (more on this below)
3. While OpenSoT, its sibling projects (e.g., CartesI/O) and all its
   dependencies are available for free as a [debian
   package](https://github.com/ADVRHumanoids/XBotControl), for the
   time being it's not open source. Consequently, it is not so trivial
   to reshape and refactor it to make it compatible to specific
   requirements.

## On this implementation
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
