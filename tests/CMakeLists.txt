# Find Google Test
find_package(GTest REQUIRED)

# Include directories for tests
include_directories(../include)

# Create a library target for PrimeCalculator
add_library(prime_calculator_lib STATIC ../src/prime_calculator_impl.cpp)
target_include_directories(prime_calculator_lib PUBLIC ../include)

# Create test executable
add_executable(prime_calculator_test test_prime_calculator.cpp)

# Link against Google Test and PrimeCalculator library
target_link_libraries(prime_calculator_test GTest::GTest GTest::Main prime_calculator_lib)

# Set target properties
set_target_properties(prime_calculator_test PROPERTIES
    OUTPUT_NAME "prime_calculator_test"
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Add test
add_test(NAME PrimeCalculatorTest COMMAND prime_calculator_test)

# Set test properties
set_tests_properties(PrimeCalculatorTest PROPERTIES
    TIMEOUT 30
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
