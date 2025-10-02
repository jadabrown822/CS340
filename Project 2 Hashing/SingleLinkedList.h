#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include "Word.h"
using namespace std;

class Node {
public:
    Word* word;
    Node* next;
    Node(Word* w) {
        word = new Word(*w);
        next = nullptr;
    }
};

class LinkedList {
    public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {};
};

#endif // SINGLE_LINKED_LIST_H