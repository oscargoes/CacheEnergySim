#!/bin/bash


# Compile C++ file
g++ test.cpp -O3 --std=c++2a -o cache_sim

# Run the compiled C++ executable
./cache_sim