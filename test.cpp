#include <iostream>
#include <chrono>
using namespace std;

// Function Declaration (or Prototype)
// This tells the compiler that the function exists.
void timedFunction();

int main() {
    // 1. Get the starting time point.
    // 'auto' infers the complex type from the function call.
    auto start_time = chrono::high_resolution_clock::now();

    // 2. Call the function you want to measure.
    timedFunction();

    // 3. Get the ending time point.
    auto end_time = chrono::high_resolution_clock::now();

    // 4. Calculate the duration.
    auto duration = end_time - start_time;

    // 5. Convert and print the duration in milliseconds.
    long long milliseconds = chrono::duration_cast<chrono::milliseconds>(duration).count();
    cout << "The function took " << milliseconds << " milliseconds to execute." << endl;

    return 0;
}

// Function Definition
// This is the actual code for the function.
void timedFunction() {
    // Simulate a time-consuming task with a loop instead of a sleep function.
    // The 'volatile' keyword prevents the compiler from optimizing away the loop entirely.
    volatile double dummy_variable = 0.0;
    for (int i = 0; i < 50000000; ++i) {
        dummy_variable += 1.0;
    }
    cout << "Function execution complete." << endl;
}