//
// Created by caleb on 7/10/2021.
//

#ifndef DUPLICATE_CHECKER_TREE_H
#define DUPLICATE_CHECKER_TREE_H

#include "treeNode.h"

class Tree {
private:
     treeNode &head;
     treeNode &top;
public:
    Tree(treeNode &head, treeNode &top);
    void Add(treeNode &newNode);
    //moves forward one
    string get();
    void reset();
    void setFirst(treeNode &newNode);
    void next();
};


#endif //DUPLICATE_CHECKER_TREE_H
