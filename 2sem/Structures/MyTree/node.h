#ifndef NODE_H
#define NODE_H

#include "QString"

class Node{
public:
    Node(QString keym, int value);

    void setLeft(Node* left);
    void setRight(Node* right);
    void setParent(Node* parent);

    Node* getLeft();
    Node* getRight();
    Node* getParent();

    QString getKey();
    int getValue();

private:
    Node* parent;
    Node* left;
    Node* right;

    QString key;
    int value;
};

#endif // NODE_H
