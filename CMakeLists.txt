cmake_minimum_required(VERSION 3.10)
project(PrimeNumberCalculator VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Output directories - handle Windows vs Unix differences
if(WIN32)
    # Windows: Use config-specific subdirectories if using multi-config generator
    if(CMAKE_CONFIGURATION_TYPES)
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<CONFIG>)
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>)
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>)
    else()
        # Single-config generator (like Unix)
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
    endif()
else()
    # Unix: Use simple bin/lib directories
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
endif()

# Compiler flags
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3 /O2")
    # Disable warnings about unsafe functions on Windows
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

# Include directories
include_directories(include)

# Add source files
set(SOURCES
    src/prime_calculator_impl.cpp
    src/prime_calculator.cpp
)

# Create main executable
add_executable(prime_calculator ${SOURCES})

# Set target properties
set_target_properties(prime_calculator PROPERTIES
    OUTPUT_NAME "prime_calculator"
)

# Enable testing
enable_testing()

# Add tests subdirectory
add_subdirectory(tests)
