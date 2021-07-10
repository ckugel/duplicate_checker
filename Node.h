//
// Created by caleb on 7/10/2021.
//

#ifndef DUPLICATE_CHECKER_NODE_H
#define DUPLICATE_CHECKER_NODE_H


class Node {
public:
    template <class V>
    Node(V data);

    Node *getNext();
    void setNext(Node *next);

    template <class V>
    V getData();

private:
    void* data;
    Node *next;
};


#endif //DUPLICATE_CHECKER_NODE_H
