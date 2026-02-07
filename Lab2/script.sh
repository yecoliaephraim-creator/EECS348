#!/bin/bash
# Lab2 script: shows directory structure and builds/cleans the project

set -e

echo "Current directory:"
pwd
echo

echo "Files in Lab2:"
ls -l
echo

echo "Building with make..."
make
echo "Build finished."
echo

echo "Running a quick test:"
./lab2 7 || true
./lab2 8 || true
echo

echo "Cleaning..."
make clean
echo "Done."
