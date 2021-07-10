//
// Created by caleb on 7/10/2021.
//

#include "LinkedList.h"

template<class T>
LinkedList::LinkedList() {
    head = nullptr;
    count = 0;
}

template <class T>
T LinkedList::peak() {
    return head->getData<T>();
}

template <class T>
T LinkedList::pop() {
    T temp = head->template getData<T>();
    head = head->getNext();
    count--;
    return temp;
}

template<> Node LinkedList::push<class T>(Node *newNode) {
    newNode->setNext(head);
    count++;
    head = newNode;
    return newNode;
}

bool LinkedList::empty() const {
    if (count >= 0) {
        return false;
    }
    else {
        return true;
    }
}

int LinkedList::size() const {
    return count;
}