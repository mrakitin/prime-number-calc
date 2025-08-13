#!/bin/bash

# Build script for Prime Number Calculator

echo "Building Prime Number Calculator..."

# Create build directory if it doesn't exist
if [ ! -d "build" ]; then
    mkdir build
    echo "Created build directory"
fi

# Navigate to build directory
cd build

# Configure with CMake
echo "Configuring with CMake..."
cmake .. || { echo "CMake configuration failed"; exit 1; }

# Build the project
echo "Building project..."
cmake --build . || { echo "Build failed"; exit 1; }

echo "Build completed successfully!"
echo ""
echo "Executables created in build/bin/:"
echo "  - prime_calculator (main program)"
echo "  - prime_calculator_test (test suite)"
echo ""
echo "To run the program:"
echo "  ./build/bin/prime_calculator <number>"
echo ""
echo "To run tests:"
echo "  ./build/bin/prime_calculator_test"
echo "  or"
echo "  cd build && ctest --output-on-failure"
