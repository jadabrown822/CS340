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

}

Node * listSearch(LinkedList * list, const string key) {
    Node* curNode = list->head;

    while (curNode != nullptr) {
        if (curNode->word->keyWord == key) {
            return curNode;
        }
        curNode = curNode->next;
    }

    return nullptr;
}

string listDescriptor(LinkedList * list) {
    ostringstream oss;
    Node* curNode = list->head;

    while (curNode != nullptr)
    {
        oss << curNode->word->descriptor();
        oss << "\n";
        curNode = curNode->next;
    }

    return oss.str();
}