//
// Created by caleb on 7/10/2021.
//

#include "LinkedList.h"


LinkedList::LinkedList() {
    head = nullptr;
    count = 0;
}


void* LinkedList::peak() {
    return head->getData();
}


Node LinkedList::pop() {
    Node temp = *head;
    head = head->getNext();
    count--;
    return temp;
}

Node LinkedList::push(Node *newNode) {
    newNode->setNext(head);
    count++;
    head = newNode;
    return *newNode;
}

bool LinkedList::empty() {
    if (head->getNext() == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

int LinkedList::size() {
    return count;
}