//
// Created by caleb on 7/10/2021.
//

#include "treeNode.h"



treeNode::treeNode(string data) {
    this->data = data;
    list = nullptr;
}

treeNode treeNode::setNext(treeNode nextNode) {
    list->push_back(nextNode);
    return nextNode;
}

deque<treeNode> treeNode::getNodes() {
    return *list;
}

string treeNode::getData() {
    return data;
}
