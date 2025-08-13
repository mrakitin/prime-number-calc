#include <gtest/gtest.h>
#include <vector>
#include "../include/prime_calculator.h"

class PrimeCalculatorTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(PrimeCalculatorTest, CalculatePrimesUpTo10) {
    std::vector<int> expected = {2, 3, 5, 7};
    std::vector<int> result = PrimeCalculator::calculatePrimes(10);
    EXPECT_EQ(result, expected);
}

TEST_F(PrimeCalculatorTest, CalculatePrimesUpTo20) {
    std::vector<int> expected = {2, 3, 5, 7, 11, 13, 17, 19};
    std::vector<int> result = PrimeCalculator::calculatePrimes(20);
    EXPECT_EQ(result, expected);
}

TEST_F(PrimeCalculatorTest, CalculatePrimesUpTo2) {
    std::vector<int> expected = {2};
    std::vector<int> result = PrimeCalculator::calculatePrimes(2);
    EXPECT_EQ(result, expected);
}

TEST_F(PrimeCalculatorTest, CalculatePrimesUpTo1) {
    std::vector<int> expected = {};
    std::vector<int> result = PrimeCalculator::calculatePrimes(1);
    EXPECT_EQ(result, expected);
}

TEST_F(PrimeCalculatorTest, CalculatePrimesUpTo0) {
    std::vector<int> expected = {};
    std::vector<int> result = PrimeCalculator::calculatePrimes(0);
    EXPECT_EQ(result, expected);
}

TEST_F(PrimeCalculatorTest, CalculatePrimesUpTo100) {
    std::vector<int> expected = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    std::vector<int> result = PrimeCalculator::calculatePrimes(100);
    EXPECT_EQ(result, expected);
}

TEST_F(PrimeCalculatorTest, PrimeCountUpTo100) {
    std::vector<int> result = PrimeCalculator::calculatePrimes(100);
    EXPECT_EQ(result.size(), static_cast<size_t>(25));
}

TEST_F(PrimeCalculatorTest, AllNumbersArePrime) {
    std::vector<int> result = PrimeCalculator::calculatePrimes(100);
    for (int prime : result) {
        // Check that each number is actually prime
        bool isPrime = true;
        if (prime < 2) {
            isPrime = false;
        } else {
            for (int i = 2; i * i <= prime; i++) {
                if (prime % i == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        EXPECT_TRUE(isPrime) << prime << " is not prime";
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
