#!/bin/bash

# Define a function to compare strings in a case-insensitive manner
function cmp_strings {
    local str1=$(echo "$1" | tr '[:upper:]' '[:lower:]')
    local str2=$(echo "$2" | tr '[:upper:]' '[:lower:]')
    if [[ "$str1" < "$str2" ]]; then
        return 0
    else
        return 1
    fi
}

# Check if strings are provided as command-line arguments
if [ $# -lt 1 ]; then
    echo "Usage: $0 <string1> <string2> ..."
    exit 1
fi

# Sort the strings using the user-defined comparison function
sorted_strings=($(printf '%s\n' "$@" | sort -f -g -k 1,1 -k 2,2 --stable --field-separator=' ' --key=1,2 \
                 --function='cmp_strings'))

# Print the sorted strings
echo "${sorted_strings[@]}"
