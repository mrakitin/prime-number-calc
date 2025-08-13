# Prime Number Calculator

A fast and efficient C++ program to calculate prime numbers using the Sieve of Eratosthenes algorithm.

## Features

- **Efficient Algorithm**: Uses the Sieve of Eratosthenes algorithm for optimal performance
- **Command Line Interface**: Simple CLI with argument-based input
- **Performance Measurement**: Includes timing information for calculations
- **Comprehensive Testing**: Full test suite using Google Test framework
- **Modern C++**: Written in C++17 with clean, maintainable code
- **CMake Build System**: Easy to build and configure
- **Proper Header Organization**: Clean separation of interface and implementation

## Algorithm

The program implements the **Sieve of Eratosthenes**, which is one of the most efficient algorithms for finding all prime numbers up to a given limit. The time complexity is O(n log log n), making it very fast for large numbers.

## Requirements

- **Compiler**: C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)
- **CMake**: Version 3.10 or higher
- **Google Test**: For running tests
- **Operating System**: Cross-platform (Windows, macOS, Linux)

## Building the Project

### Prerequisites

1. **Install CMake**: Download from [cmake.org](https://cmake.org/download/)
2. **Install Google Test**:
   - **Ubuntu/Debian**: `sudo apt-get install libgtest-dev`
   - **macOS**: `brew install googletest`
   - **Windows**: Use vcpkg or download from GitHub

### Build Steps

```bash
# Create build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build the project
cmake --build .

# Or use make on Unix-like systems
make
```

**Or use the provided build script:**
```bash
./build.sh
```

## Usage

### Running the Program

```bash
# Basic usage
./build/bin/prime_calculator <max_number>

# Examples
./build/bin/prime_calculator 100
./build/bin/prime_calculator 1000
./build/bin/prime_calculator 10000
```

### Example Output

```
Calculating prime numbers up to 100...
Prime numbers found: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
Total count: 25
Calculation time: 6 microseconds
```

## Running Tests

```bash
# Run tests
cd build
ctest --output-on-failure

# Or run the test executable directly
./build/bin/prime_calculator_test
```

## Project Structure

```
prime-number-calc/
├── CMakeLists.txt              # Main CMake configuration
├── README.md                   # This file
├── build.sh                    # Build script
├── include/
│   └── prime_calculator.h     # Header file with class declarations
├── src/
│   ├── prime_calculator_impl.cpp # Implementation of PrimeCalculator class
│   └── prime_calculator.cpp   # Main function and program entry point
└── tests/
    ├── CMakeLists.txt         # Test CMake configuration
    └── test_prime_calculator.cpp # Test suite
```

## Code Organization

The project follows modern C++ best practices:

- **Header Files** (`include/`): Contain class declarations and function prototypes
- **Implementation Files** (`src/`): Contain the actual implementation
- **Separation of Concerns**: Main function is separate from class implementation
- **Reusable Library**: PrimeCalculator class can be used in other projects

## Performance

The Sieve of Eratosthenes algorithm provides excellent performance:
- **Time Complexity**: O(n log log n)
- **Space Complexity**: O(n)
- **Memory Efficient**: Uses boolean array for marking

**Performance Examples:**
- Up to 100: ~6 microseconds
- Up to 10,000: ~72 microseconds

## Error Handling

The program includes comprehensive error handling:
- Invalid command line arguments
- Non-numeric input
- Negative numbers
- Numbers too large for int type

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests for new functionality
5. Ensure all tests pass
6. Submit a pull request

## License

This project is open source and available under the MIT License.

## Author

Created as a demonstration of efficient prime number calculation algorithms in C++.

## Acknowledgments

- **Sieve of Eratosthenes**: Ancient Greek mathematician (276-194 BC)
- **Google Test**: Excellent C++ testing framework
- **CMake**: Powerful build system generator
