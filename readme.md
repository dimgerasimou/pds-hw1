# Parallel and Distributed Systems
Department of Electrical and Computer Engineering
Aristotle University of Thessaloniki

## Description

In this repo is located the source code required for the first homework exercise of the course Parallel and Distributed Systems.

## Dependencies

- libmatio
- opencilk (check that opencilk's clang is the one found in path)
- pthreads
- openmp

## Execution

Make sure that cilk path is correct for you installation in makefile.

You can compile it with `make`. To run use `./pardis0 "path_to_dataset.mat"`.