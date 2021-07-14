//
// Created by caleb on 7/10/2021.
//

#ifndef DUPLICATE_CHECKER_LINKEDLIST_H
#define DUPLICATE_CHECKER_LINKEDLIST_H


#include "Node.h"

class LinkedList {
private:
    Node *head;
    int count;
public:
    LinkedList();

    void* peak();
    Node pop();
    Node push(Node *newNode);

    bool empty();
    int size();
};


#endif //DUPLICATE_CHECKER_LINKEDLIST_H
