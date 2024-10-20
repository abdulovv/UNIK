#ifndef TREE_H
#define TREE_H

#include "node.h"

class Tree{
public:
    Tree();

    Node* addNode(Node* newNode, Node* currentNode);
    Node* getRoot();
    Node* balance(Node* node);
    void setRoot(Node* root);

    int getBalanceFactor(Node* node);
    Node* rightRotate(Node* x);
    Node* leftRotate(Node* x);
    void goTree(Node* currentNode);

    // int getHeight(Node* node);
    // int getBalanceFactor(Node* node);

private:
    Node* root;

};

#endif // TREE_H
