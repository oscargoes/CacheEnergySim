#!/bin/bash

## NEED TO BE USING C++13
## g++ Version needs to be 10 or higher
## As it is needed for a used library in the code

# Compile C++ file
g++ test.cpp -O3 --std=c++2a -o cache_sim

# Run the compiled C++ executable
./cache_sim