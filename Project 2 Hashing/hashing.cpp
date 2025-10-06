#include "SingleLinkedList.h"

#include <iostream>
#include <string>
#include <sstream>
#include <ostream>
#include <iomanip>
#include <string>

using namespace std;

Node * listSearch(LinkedList * list, const string key);
string listDescriptor(LinkedList * list);

int main() {
    /*
        use the hask table example from the pdf

        make hash table have own functions that calls the node function, make separate csv files with size.csv as output

        look at the linked list from cs150
        make Person the number to find the node, id is the word, with frequency and step count

        make the hash table size the mod to get items into node, or start at beginning note then double the first few nodes if too big

        input the LittleWomen.txt file and output it to a csv file
        
    */
}


Node * listSearch(LinkedList * list, const string key) {
    Node * current = list->head;

    while (current != nullptr) {
        if (current->hashed_key->keyWord == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}


string listDescriptor(LinkedList * list) {
    ostringstream oss;

    Node* current = list->head;

    while (current != nullptr) {
        oss << current->hashed_key->descriptor();
        oss << "\n";

        current = current->next;
    }
    return oss.str();
}