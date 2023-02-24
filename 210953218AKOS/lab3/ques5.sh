#!/bin/bash

echo "Enter the file extension to copy:"
read ext

echo "Enter the destination folder:"
read dest

# Create the destination folder if it doesn't exist
mkdir -p "$dest"

# Copy all files with the specified extension to the destination folder
for file in *."$ext"; do
    if [ -f "$file" ]; then
        cp "$file" "$dest"
    fi
done

echo "Files with extension .$ext copied to $dest."
