# pimpc - Nonlinear MPC (NMPC) with OpenMP for the Raspberry Pi

This project contains a nonlinear MPC solver built on the real-time iterations
sequential quadratic programming (SQP) scheme.

The "qpon" (qpOASES native) version uses the normal C++ version of qpOASES
built as a dynamic library (.so) and is statically linked at compile time.

It is autocoded from MATLAB/Simulink for repeatability and ease of
testing/debugging.

## Requirements
A working build system, OpenMP.

## Build

Run `$ make` and execute the resulting binary `uln_rti`.

Jon Sowman 2017, All rights reserved.

