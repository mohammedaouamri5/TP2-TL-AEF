#!/bin/bash
echo "\n----------------------------------(run)----------------------------------\n"
# Set default value for argument
build_type=${1:-"x86_64_Debug"}
 

# Create LOG directory if it doesn't exist

# Get the current date and time
YMD=$(date +"%Y-%m-%d")
HMS=$(date +"%H:%M:%S")
mkdir -p LOG/${YMD}

# Run the make command with the specified argument
"bin/${build_type}/TP" 2>&1 | tee  LOG/"$YMD"/"$HMS"-run-"$build_type".LOG
echo "\n----------------------------------(end)----------------------------------\nat"  LOG/"$YMD"/"$HMS"-run-"$build_type".LOG 

