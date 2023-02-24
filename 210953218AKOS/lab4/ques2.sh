#!/bin/bash

# Check if filenames are provided as command-line arguments
if [ $# -lt 1 ]; then
    echo "Usage: $0 <filename1> <filename2> ..."
    exit 1
fi

# Loop through each filename
for file in "$@"; do
    # Check if file exists and is a regular file
    if [ -f "$file" ]; then
        # Prompt the user for confirmation before removing the file
        read -p "Are you sure you want to delete $file? [y/N] " confirm
        if [[ "$confirm" == [yY] || "$confirm" == [yY][eE][sS] ]]; then
            # Remove the file
            rm "$file"
            echo "File $file deleted"
        else
            echo "File $file not deleted"
        fi
    else
        echo "Error: $file is not a regular file"
    fi
done
