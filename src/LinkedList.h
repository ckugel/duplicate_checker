//
// Created by caleb on 7/10/2021.
//

#ifndef DUPLICATE_CHECKER_LINKEDLIST_H
#define DUPLICATE_CHECKER_LINKEDLIST_H



#include <iostream>
using namespace std;

#include "Node.h"

class LinkedList {
private:
    Node *head;
    int count;
public:
    LinkedList();

    string peak();
    Node pop();
    Node push(string data);

    bool empty();
    int size();
};


#endif //DUPLICATE_CHECKER_LINKEDLIST_H
