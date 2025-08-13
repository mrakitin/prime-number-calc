#include "prime_calculator.h"
#include <iostream>
#include <vector>

std::vector<int> PrimeCalculator::calculatePrimes(int maxNumber) {
    if (maxNumber < 2) {
        return {};
    }

    // Create a boolean array "isPrime[0..maxNumber]" and initialize
    // all entries as true
    std::vector<bool> isPrime(maxNumber + 1, true);
    isPrime[0] = isPrime[1] = false;

    // Use Sieve of Eratosthenes algorithm
    for (int p = 2; p * p <= maxNumber; p++) {
        if (isPrime[p]) {
            // Mark all multiples of p as not prime
            for (int i = p * p; i <= maxNumber; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Collect all prime numbers
    std::vector<int> primes;
    for (int i = 2; i <= maxNumber; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

void PrimeCalculator::printPrimes(const std::vector<int>& primes) {
    if (primes.empty()) {
        std::cout << "No prime numbers found in the given range." << std::endl;
        return;
    }

    std::cout << "Prime numbers found: ";
    for (size_t i = 0; i < primes.size(); ++i) {
        std::cout << primes[i];
        if (i < primes.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
    std::cout << "Total count: " << primes.size() << std::endl;
}
