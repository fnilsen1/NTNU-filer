#include <iostream>
#include <std_lib_facilities.h>

// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n == 0) return 1;
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to calculate binomial coefficient nCk
unsigned long long binomial_coeff(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Function to calculate binomial probability
double binomial_probability(int n, int k, double p) {
    double prob = 0.0;
    for (int i = k; i <= n; ++i) {
        prob += binomial_coeff(n, i) * pow(p, i) * pow(1 - p, n - i);
    }
    return prob;
}

int main() {
    int n = 80000000;     // Number of trials
    int k = 1;      // Minimum number of successes
    double p = 0.000002; // Probability of success in each trial

    double probability = binomial_probability(n, k, p);
    std::cout << "The probability of getting at least " << k << " successes in "
              << n << " trials is " << probability << std::endl;

    return 0;
}
