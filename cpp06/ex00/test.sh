#!/bin/bash

# Set the path to your executable
EXECUTABLE="./converter"

# Array of command line arguments
ARGS=("0" "-1" "+inf" "nan" "-inf" "+inff" "-inff" "127" "128" "2147483647" "2147483648" "3.402823e+38" "3.402824e+38")

# Output file
OUTPUT_FILE="output.txt"

# Truncate the output file
> $OUTPUT_FILE

# Loop through each argument and run the executable
for arg in "${ARGS[@]}"; do
    echo "Running with argument: $arg"
	echo "arg[\"$arg\"]:" >> $OUTPUT_FILE
    $EXECUTABLE $arg >> $OUTPUT_FILE
    echo "---------------------------------" >> $OUTPUT_FILE
done

echo "Script completed. Output saved to $OUTPUT_FILE"
