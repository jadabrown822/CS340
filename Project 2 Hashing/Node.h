#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

// struct that holds each unque word
struct HashTableNode {
    string word;
    int occurrences;
    long long totalSteps;
    HashTableNode* next;        // the pointer for the linked list chain

    // constructor
    HashTableNode(const string& w) : word(w), occurrences(1), totalSteps(0), next(nullptr) {}
};

#endif // NODE_H