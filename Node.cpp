//
// Created by caleb on 7/10/2021.
//

#include "Node.h"

Node::Node(const BYTE data) {
    this->data = data;
}

Node *Node::getNext(){
    return next;
}

void Node::setNext(Node *next) {
    this->next = next;
}

const BYTE Node::getData() const {
    return data;
}

