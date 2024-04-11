//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include <chrono>

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main() {
    auto start = std::chrono::high_resolution_clock::now();

    long long sum = 0;
    for (int i = 0; i < 1000000001; i++)
    {
        sum+=i;
    };

    cout << sum << endl;
    
     auto end = std::chrono::high_resolution_clock::now();


    std::chrono::duration<double> duration = end - start;

    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
    int sup;
    cin >> sup;

    return 0;
}