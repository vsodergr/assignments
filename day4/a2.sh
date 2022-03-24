#!/bin/bash

if [ ! -d assignments ]; then
  echo "Cloning repo..."
  git clone https://github.com/vsodergr/assignments.git
else
  echo "Repo already exists. Skipping cloning."
fi

echo "Building assignment..."
g++ assignments/day2-3/a2.cpp -o run_me

echo "Running assignment..."
./run_me
