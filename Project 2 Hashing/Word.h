#ifndef WORD_H
#define WORD_H

#include <string>
#include <sstream>
using namespace std;

class Word {
    public:
    string keyWord;
    int frequency;
    int steps;

    Word(const string& key = "na", const int frequency = 0, const int steps = 0): keyWord(key), frequency(frequency), steps(steps) {}

    string descriptor() const {
        ostringstream oss;
        oss << "Word: " << keyWord
            << ", Frequency: "
            << frequency
            << ", Steps: " << steps;
        
        return oss.str();
    }
};

#endif // WORD_H