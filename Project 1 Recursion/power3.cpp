#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>

using namespace std;

int main() {

    for(int i=3; i<=35; ++i) {
        auto start_time = chrono::high_resolution_clock::now();

        // RM4(a,n)

        auto end_time = chrono::high_resolution_clock::now();

        auto duration = end_time - start_time;

        long long nanoseconds = chrono::duration_cast<chrono::nanoseconds>(duration).count();

        cout << "N = " << i << endl;
        // cout << answer << endl;
        cout << nanoseconds << " nanoseconds." << endl;
    }

    for(int i=3; i<=35; ++i) {
        auto start_time = chrono::high_resolution_clock::now();

        // RM6(a,n)

        auto end_time = chrono::high_resolution_clock::now();

        auto duration = end_time - start_time;

        long long nanoseconds = chrono::duration_cast<chrono::nanoseconds>(duration).count();
        
        cout << "N = " << i << endl;
        // cout << answer << endl;
        cout << nanoseconds << " nanoseconds." << endl;
    }

    return 0;
}