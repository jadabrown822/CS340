#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include "Node.h"

using namespace std;

int HashCode(const string& str) {
    long long h = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        h = (h * 31) + static_cast<int>(str[i]);
    }

    return h;
}


class HashTable {
    private:
        size_t tableSize;
        vector<HashTableNode*> buckets;

        // convert word to lovercase
        string toLowerLetter(const string& str) {
            string lowerStr = str;
            for (char& c : lowerStr) {
                c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
            }
            return lowerStr;
        }

    public:
        // constructor
        HashTable(size_t size) : tableSize(size), buckets(size, nullptr) {}

        // destructor
        ~HashTable () {
            for (size_t i = 0; i < tableSize; ++i) {
                HashTableNode* current = buckets[i];
                while (current != nullptr) {
                    HashTableNode* next = current->next;
                    delete current;
                    current = next;
                }
            }
        }

        // search, locate, and insert word into the hash table
        void searchAndInsert (const string& word, long long& totalWords, long long& totalSteps) {
            string lowerWord = toLowerLetter(word);

            // use abs() for hash index with % tableSize
            int hashVal = HashCode(lowerWord);
            size_t index = static_cast<size_t>(abs(hashVal) % tableSize);

            // treverse and search the linked list at the bucket
            HashTableNode* current = buckets[index];
            HashTableNode* prev = nullptr;
            int steps = 0;
            bool found = false;

            // traverse the linked list or chain
            while (current != nullptr) {
                steps++;        // step counter for the current position
                if (current->word == lowerWord) {
                    found = true;       // word found

                    // update occurrences and totalSteps
                    current->occurrences++;
                    current->totalSteps += steps;       // total steps = position * occurrences
                    totalWords++;                       // increment total words
                    totalSteps += steps;                // total steps for the hash table

                    break;      // exit the loop
                }
                prev = current;
                current = current->next;
            }

            // if there is a collision or the word is not found
            if (!found) {

                // word is not found, add to the end of the chain
                steps++;        // step counter for the new position

                HashTableNode* newNode = new HashTableNode(lowerWord);      // create a new node, occurences starts at 1

                // new node entry starts at 1 occurence
                newNode->totalSteps = steps;        // total steps = position * occurrences (1)
                totalWords++;                       // increment total words
                totalSteps += steps;                // total steps for the hash table

                if (prev == nullptr) {
                    // list is empty (first element in the bucket)
                    buckets[index] = newNode;
                }
                else {
                    // append to the end of the chain
                    prev->next = newNode;
                }
            }
        }

        // getter for bucket vector (helps with csv export)
        const vector<HashTableNode*>& getBuckets() const {
            return buckets;
        }

        // getter for table size
        size_t getTableSize() const {
            return tableSize;
        }
};

#endif // HASHTABLE_H