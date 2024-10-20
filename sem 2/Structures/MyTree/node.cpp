#include "node.h"

Node::Node(QString key, int value) {
    this->key = key;
    this->value = value;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

void Node::setLeft(Node* left){
    this->left = left;
}

void Node::setRight(Node* right){
    this->right = right;
}

void Node::setParent(Node* parent){
    this->parent = parent;
}

Node* Node::getLeft(){
    return left;
}

Node* Node::getRight(){
    return right;
}

Node* Node::getParent(){
    return parent;
}

QString Node::getKey(){
    return key;
}

int Node::getValue(){
    return value;
}
