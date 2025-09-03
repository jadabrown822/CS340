#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>
using namespace std;


int tower(int diskNum, char sourcePeg, char targetPeg, char tempPeg);

int main() {
    int n = 0;


    for(int i=3; i<=35; ++i) {
        int stepCount = 0;


        auto start_time = chrono::high_resolution_clock::now();

        stepCount = tower(i, 'A', 'C', 'B');

        auto end_time = chrono::high_resolution_clock::now();

        auto duration = end_time - start_time;

        long long milliseconds = chrono::duration_cast<chrono::milliseconds>(duration).count();

        cout << "N = " << n << endl;
        cout << "That took " << stepCount << " steps." << endl;
        cout << milliseconds << " milliseconds." << endl;

    }
}