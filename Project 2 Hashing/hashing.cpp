#include "HashTable.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// constants
const vector<size_t> TABLE_SIZES = {500, 1000, 2000, 5000,10000};
const string INPUT_FILE = "C:/Users/jadab/OneDrive/Documents/CS340/Project 2 Hashing/LittleWomen.txt";
const string OUTPUT_FILE = "C:/Users/jadab/OneDrive/Documents/CS340/Project 2 Hashing/";

// function prototypes
void processFile(const string& filename, HashTable& table, long long& totalWords, long long& totalSteps);
void exportResults(const HashTable& table, const string& outputFilePath);


int main() {
    map<size_t, double> avgStepsMap;   // map to hold average steps for each table size

    for (size_t size : TABLE_SIZES) {
        cout << "Processing table size: " << size << endl;

        // reset counters
        long long totalWords = 0;
        long long totalSteps = 0;

        // create hash table
        HashTable table(size);

        // process the input file
        processFile(INPUT_FILE, table, totalWords, totalSteps);

        // calculate results
        double avgSteps = 0.0;
        if (totalWords > 0) {
            avgSteps = static_cast<double>(totalSteps) / totalWords;
        }

        // store results in map
        avgStepsMap[size] = avgSteps;

        // information output
        cout << "Table Size: " << size << endl;
        cout << "Total Unique Words: " << totalWords << endl;
        cout << "Total Steps: " << totalSteps << endl;
        cout << "Average Steps per Word: " << fixed << setprecision(2) << avgSteps << endl;

        stringstream ss;
        ss << "HashTable_" << size << ".csv";
        string fileNamePart = ss.str();

        string outputFilePath = OUTPUT_FILE + fileNamePart;

        // export results to CSV
        exportResults(table, outputFilePath);

        cout << "Results exported to " << outputFilePath << endl;
    }

    cout << "\nSummary of Average Steps per Table Size:" << endl;
    for (const auto& pair : avgStepsMap) {
        cout << "Table Size: " << pair.first << ", Average Steps: " << fixed << setprecision(2) << pair.second << endl;
    }

    return 0;
}


void processFile(const string& filename, HashTable& table, long long& totalWords, long long& totalSteps) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string word;
    while (inputFile >> word) {
        table.searchAndInsert(word, totalWords, totalSteps);
    }

    inputFile.close();
}


void exportResults(const HashTable& table, const string& outputFilePath) {
    ofstream outputFile(outputFilePath);

    if (!outputFile.is_open()) {
        cerr << "Error opening output file: " << outputFilePath << endl;
        return;
    }

    outputFile << fixed << setprecision(4);

    outputFile << "Word,Occurrences,TotalSteps,AverageSteps\n";

    for (size_t i = 0; i < table.getTableSize(); ++i) {
        HashTableNode* current = table.getBuckets()[i];

        while (current != nullptr) {
            double avgSteps = 0.0;
            if (current->occurrences > 0) {
                avgSteps = static_cast<double>(current->totalSteps) / current->occurrences;
            }
            outputFile << current->word << "," << current->occurrences << "," << current->totalSteps << "," << avgSteps << "\n";
            current = current->next;
        }
    }

    outputFile.close();
}