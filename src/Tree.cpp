//
// Created by caleb on 7/10/2021.
//

#include "Tree.h"


Tree::Tree(treeNode &head, treeNode &top) : head(head), top(top) {}

void Tree::Add(treeNode &newNode) {
    head.setNext(newNode);
}

void Tree::reset() {
    head = top;
}

void Tree::setFirst(treeNode &newNode) {
    top = newNode;
    Add(newNode);
}

// gets head sets head to next and removes the thing got
string Tree::get() {
    treeNode temp = head;
    next();
    temp.getNodes().pop_front();
    return temp.getData();
}

void Tree::next() {
    head = head.getNodes().front();
}
