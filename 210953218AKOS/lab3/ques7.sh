#!/bin/bash

# Check if filename is provided as command-line argument
if [ $# -ne 1 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

# Check if file exists and is a regular file
if [ ! -f "$1" ]; then
    echo "Error: $1 is not a regular file"
    exit 1
fi

# Use awk to delete even numbered lines from file
awk 'NR % 2 == 1 { print }' "$1" > tmp && mv tmp "$1"
