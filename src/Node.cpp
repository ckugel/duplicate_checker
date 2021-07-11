//
// Created by caleb on 7/10/2021.
//

#include "Node.h"

Node::Node(void* data) {
    this->data = data;
    next = nullptr;
}

Node *Node::getNext(){
    return next;
}

void Node::setNext(Node *next) {
    this->next = next;
}

void *Node::getData() {
    return data;
}

