#!/bin/bash

# Check if source and destination filenames are provided as command-line arguments
if [ $# -ne 2 ]; then
    echo "Usage: $0 <source_file> <destination_file>"
    exit 1
fi

# Check if source file exists and is a regular file
if [ ! -f "$1" ]; then
    echo "Error: $1 is not a regular file"
    exit 1
fi

# Make a copy of the source file to the destination file
cp "$1" "$2"

# Check if the copy was successful
if [ $? -eq 0 ]; then
    echo "File copied successfully"
else
    echo "Error: File could not be copied"
fi
