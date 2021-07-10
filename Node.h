//
// Created by caleb on 7/10/2021.
//

#ifndef DUPLICATE_CHECKER_NODE_H
#define DUPLICATE_CHECKER_NODE_H

#include <bitset>

using namespace std;

typedef bitset<8> BYTE;

class Node {
public:
    Node(const BYTE data);

    Node *getNext();
    void setNext(Node *next);

    const BYTE getData() const;

private:
    BYTE data;
    Node *next;
};


#endif //DUPLICATE_CHECKER_NODE_H
