#!/bin/bash

echo "Enter the basic salary:"
read basic

echo "Enter the travel allowance (TA):"
read ta

# Calculate the gross salary using bc command for floating point arithmetic
gs=$(echo "$basic + $ta + 0.1 * $basic" | bc)

echo "Gross salary: $gs"
