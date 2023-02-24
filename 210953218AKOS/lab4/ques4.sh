#!/bin/bash

# Parse command-line options
while [[ "$1" =~ ^- ]]; do
    case "$1" in
        -linecount)
            linecount=true
            ;;
        -wordcount)
            wordcount=true
            ;;
        -charcount)
            charcount=true
            ;;
        *)
            echo "Invalid option: $1" >&2
            exit 1
            ;;
    esac
    shift
done

# Check if options are provided


# Check if input file exists and is readable
if [ ! -r "$1" ]; then
    echo "Input file not found or not readable: $1" >&2
    exit 1
fi

# Perform line count if -linecount option is provided
if [ "$linecount" = true ]; then
    lines=$(wc -l < "$1")
    echo "Line count: $lines"
fi

# Perform word count if -wordcount option is provided
if [ "$wordcount" = true ]; then
    words=$(wc -w < "$1")
    echo "Word count: $words"
fi

# Perform character count if -charcount option is provided
if [ "$charcount" = true ]; then
    chars=$(wc -c < "$1")
    echo "Character count: $chars"
fi
