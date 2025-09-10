#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <random>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

void randArray(int a[20], int n);
void sortArray(int a[20], int n);
// Brute force
// Greedy


int main() {
	const int size = 20;
    int myArray[20];

    randArray(myArray, size);

    sortArray(myArray, size);

    // time start

    // int brute force

    // time end

    // duration

    // cout << bfAnswer << endl;
    // cout << bfTime << endl;


    // time start

    // int greedy

    // time end

    // duration

    // cout << greedyAnswer << endl;
    // cout << greedyTime << endl;

    
    return 0;
}


void randArray(int a[20], int n){
    srand(time(0));

    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 150 + 1;
    }

    cout << "Random Array: [ ";

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << " ]" << endl;
}


void sortArray(int a[20], int n){
    int temp;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (a[j] < a[j+1]) {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }

        cout << "Sorted Array: [ ";

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << " ]" << endl;
}


// brute force


// greedy