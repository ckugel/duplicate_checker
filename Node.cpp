//
// Created by caleb on 7/10/2021.
//

#include "Node.h"

template<class V>
Node::Node(V data) {
}

Node *Node::getNext(){
    return next;
}

void Node::setNext(Node *next) {
    this->next = next;
}

template<class V>
V Node::getData() {
    return (V*) data;
}



