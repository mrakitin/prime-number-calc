#include "prime_calculator.h"
#include <iostream>
#include <string>
#include <chrono>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <max_number>" << std::endl;
        std::cerr << "Example: " << argv[0] << " 100" << std::endl;
        return 1;
    }

    try {
        int maxNumber = std::stoi(argv[1]);

        if (maxNumber < 0) {
            std::cerr << "Error: Please provide a non-negative number." << std::endl;
            return 1;
        }

        std::cout << "Calculating prime numbers up to " << maxNumber << "..." << std::endl;

        auto start = std::chrono::high_resolution_clock::now();
        std::vector<int> primes = PrimeCalculator::calculatePrimes(maxNumber);
        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        PrimeCalculator::printPrimes(primes);
        std::cout << "Calculation time: " << duration.count() << " microseconds" << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Invalid number format. Please provide a valid integer." << std::endl;
        return 1;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: Number too large." << std::endl;
        return 1;
    }

    return 0;
}
