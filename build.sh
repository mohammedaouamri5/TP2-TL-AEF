#!/bin/bash

# Set default value for argument
build_type=${1:-"debug_x86_64"}

 
# Get the current date and time
YMD=$(date +"%Y-%m-%d")
HMS=$(date +"%H:%M:%S")
mkdir -p LOG/${YMD}

# Run the make command with the specified argument
make config="$build_type" 2>&1 | tee "LOG/${YMD}/${HMS}-build-${build_type}.LOG" 



