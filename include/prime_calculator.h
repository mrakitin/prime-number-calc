#ifndef PRIME_CALCULATOR_H
#define PRIME_CALCULATOR_H

#include <vector>

class PrimeCalculator {
public:
    /**
     * Calculate all prime numbers up to the given maximum number
     * @param maxNumber The upper limit for prime number calculation
     * @return Vector containing all prime numbers from 2 to maxNumber
     */
    static std::vector<int> calculatePrimes(int maxNumber);

    /**
     * Print the list of prime numbers to standard output
     * @param primes Vector of prime numbers to display
     */
    static void printPrimes(const std::vector<int>& primes);
};

#endif // PRIME_CALCULATOR_H
