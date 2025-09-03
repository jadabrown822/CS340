#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>
using namespace std;


void tower(int diskNum, char sourcePeg, char targetPeg, char tempPeg, long long& numSteps);

int main() {
    int n = 0;


    for(int i=3; i<=35; ++i) {
        long long stepCount = 0;


        auto start_time = chrono::high_resolution_clock::now();

        tower(i, 'A', 'C', 'B', stepCount);

        auto end_time = chrono::high_resolution_clock::now();

        auto duration = end_time - start_time;

        long long milliseconds = chrono::duration_cast<chrono::milliseconds>(duration).count();

        cout << "N = " << i << endl;
        cout << "That took " << stepCount << " steps." << endl;
        cout << milliseconds << " milliseconds." << endl;

    }
}


void tower(int diskNum, char sourcePeg, char targetPeg, char tempPeg, long long& numSteps) {
    if (diskNum == 1) {
        ++numSteps;
        return;
    }

    else {
        tower(diskNum - 1, sourcePeg, tempPeg, targetPeg, numSteps);
        ++numSteps;
        tower(diskNum - 1, tempPeg, targetPeg, sourcePeg, numSteps);
    }
}