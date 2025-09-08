#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>

using namespace std;

long long RM4(int a, int n);
long long RM6(int a, int n);

int main() {

    for(int i=3; i<=35; ++i) {
        auto start_time = chrono::high_resolution_clock::now();

        long long answer = RM4(3,i);

        auto end_time = chrono::high_resolution_clock::now();

        auto duration = end_time - start_time;

        long long nanoseconds = chrono::duration_cast<chrono::nanoseconds>(duration).count();

        cout << "N = " << i << endl;
        cout << answer << endl;
        cout << nanoseconds << " nanoseconds." << endl;
    }

    for(int i=3; i<=35; ++i) {
        auto start_time = chrono::high_resolution_clock::now();

        long long answer = RM6(3,i);

        auto end_time = chrono::high_resolution_clock::now();

        auto duration = end_time - start_time;

        long long nanoseconds = chrono::duration_cast<chrono::nanoseconds>(duration).count();
        
        cout << "N = " << i << endl;
        cout << answer << endl;
        cout << nanoseconds << " nanoseconds." << endl;
    }

    return 0;
}


long long RM4(int a, int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return static_cast<long long>(a) * RM4(a, n-1);
    }
}


long long RM6(int a, int n) {
    if (n == 0) {
        return 1;
    }
    else if (n % 2 == 0) {
        return pow(RM6(a, n/2), 2);
    }
    else {
        return static_cast<long long>(a) * pow(RM6(a, n/2), 2);
    }
}