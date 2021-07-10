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
    template <class T>
    T peak();
    template <class T>
    T pop();
    template <class T>
    Node push(Node *newNode);
    [[nodiscard]] bool empty() const;
    [[nodiscard]] int size() const;
};


#endif //DUPLICATE_CHECKER_LINKEDLIST_H
