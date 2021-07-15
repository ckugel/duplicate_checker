//
// Created by caleb on 7/10/2021.
//

#ifndef DUPLICATE_CHECKER_NODE_H
#define DUPLICATE_CHECKER_NODE_H

#include <iostream>
using namespace std;


class Node {
public:
    explicit Node(string data);

    Node *getNext();
    void setNext(Node *pNode);

    string getData();

private:
    Node *next;
    string data;
};


#endif //DUPLICATE_CHECKER_NODE_H
