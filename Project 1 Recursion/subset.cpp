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
int bruteForce(int a[20]);
int greedy(int a[20], int n);


int main() {
	const int size = 20;
    int myArray[20];

    randArray(myArray, size);

    sortArray(myArray, size);

    auto bfStart = chrono::high_resolution_clock::now();

    int bfAnswer = bruteForce(myArray);

    auto bfEnd = chrono::high_resolution_clock::now();

    auto bfDuration = bfEnd - bfStart;

    long long bfTime = chrono::duration_cast<chrono::nanoseconds>(bfDuration).count();

    cout << "Brute Force Answer: " << bfAnswer << endl;
    cout << "Brute Force Time: " << bfTime << " nanoseconds." << endl;


    auto greedyStart = chrono::high_resolution_clock::now();

    int greedyAnswer = greedy(myArray, size);

    auto greedyEnd = chrono::high_resolution_clock::now();

    auto greedyDuration = greedyEnd - greedyStart;

    long long greedyTime = chrono::duration_cast<chrono::nanoseconds>(greedyDuration).count();

    cout << "Greedy Algorithm Answer: " << greedyAnswer << endl;
    cout << "Greedy Algorithm Time: " << greedyTime << " nanoseconds." << endl;

    
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


int bruteForce(int a[20]) {
    int max = 1000;
    int total = 0;
    int i = 0;

    while (total <= max) {
        total = total + a[i];
        i++;
    }

    i--;
    total = total - a[i];

    return total;
}


int greedy(int a[20], int n) {
    int max = 1000;
    int total = 0;

    for (int i = 0; i < n; i++) {
        total = total + a[i];

        if (total > max) {
            total  = total - a[i];
        }
        if (total == max) {
            return total;
        }
    }

    return total;
}