#!/bin/bash

cmake -S . -B build
cmake --build build/ -j 8
cd build/
ctest
cd ..
