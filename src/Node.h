//
// Created by caleb on 7/10/2021.
//

#ifndef DUPLICATE_CHECKER_NODE_H
#define DUPLICATE_CHECKER_NODE_H


class Node {
public:
    explicit Node(void* data);

    Node *getNext();
    void setNext(Node *pNode);

    void* getData();

private:
    Node *next;
    void* data;
};


#endif //DUPLICATE_CHECKER_NODE_H
