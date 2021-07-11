//
// Created by caleb on 7/10/2021.
//

#ifndef DUPLICATE_CHECKER_TREENODE_H
#define DUPLICATE_CHECKER_TREENODE_H

#include <iostream>
#include <deque>

using namespace std;

class treeNode {
private:
    string data;
    deque<treeNode> *list;
    string getData();
public:
    string getdata;
    deque<treeNode> getNodes();
    treeNode setNext(treeNode nextNode);
    explicit treeNode(string data);
};


#endif //DUPLICATE_CHECKER_TREENODE_H
