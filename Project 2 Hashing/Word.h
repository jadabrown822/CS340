#ifndef WORD_H
#define WORD_H

#include <string>
#include <sstream>
using namespace std;

class Word {
    public:
        string keyWord;
        int frequency;
        int stepCount;

        Word(const string& keyWord = "na", const int frequency = 0, const int stepCount = 0) : keyWord{keyWord}, frequency{frequency}, stepCount{stepCount} {}

        string descriptor() const {
            ostringstream oss;

            oss << "Key Word: " << keyWord << ","
                << "Occurence: " << frequency << ", "
                << "Steps: " << stepCount << endl;

            return oss.str();
        }
};

#endif // WORD_H