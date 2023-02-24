#!/bin/bash

# Check if input file is provided as command-line argument
if [ $# -lt 1 ]; then
    echo "Usage: $0 <input_file>"
    exit 1
fi

input_file=$1

# Check if input file exists
if [ ! -f "$input_file" ]; then
    echo "Input file does not exist"
    exit 1
fi

# Function to search for a pattern in the input file
function search_pattern {
    pattern=$1
    echo "Lines containing '$pattern' in '$input_file':"
    grep "$pattern" "$input_file"
}

# Function to delete all occurrences of a pattern in the input file
function delete_pattern {
    pattern=$1
    sed -i "/$pattern/d" "$input_file"
    echo "Deleted all occurrences of '$pattern' in '$input_file'"
}

# Menu
while true; do
    echo ""
    echo "Select an option:"
    echo "1. Search for a pattern in the input file"
    echo "2. Delete all occurrences of a pattern in the input file"
    echo "3. Exit"
    read -p "Enter your choice (1-3): " choice

    case $choice in
        1)
            read -p "Enter the pattern to search: " pattern
            search_pattern "$pattern"
            ;;
        2)
            read -p "Enter the pattern to delete: " pattern
            delete_pattern "$pattern"
            ;;
        3)
            exit 0
            ;;
        *)
            echo "Invalid choice"
            ;;
    esac
done
