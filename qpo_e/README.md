# pimpc - Nonlinear MPC (NMPC) with OpenMP for the Raspberry Pi

This project contains a nonlinear MPC solver built on the real-time iterations
sequential quadratic programming (SQP) scheme.

The "qpo_e" ("embedded" qpOASES - a plain-C port) version does not compile or
runtime link the qpOASES library. The qpOASES_e version is statically linked at
compile time. This version does not require any runtime memory
allocation/management (i.e. no `new`, `malloc` etc).

It is autocoded from MATLAB/Simulink for repeatability and ease of
testing/debugging.

## Requirements
A working build system, OpenMP.

## Build

Run `$ make` and execute the resulting binary `uln_rti`.

Jon Sowman 2017, All rights reserved.

