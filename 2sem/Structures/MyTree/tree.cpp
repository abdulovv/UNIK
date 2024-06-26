#include "tree.h"

Tree::Tree() {
    root = nullptr;
}

Node* Tree::addNode(Node* newNode, Node* currentNode){
    if(currentNode == nullptr){
        root = newNode;
        root->setParent(nullptr);
        root->setLeft(nullptr);
        root->setRight(nullptr);
        return balance(newNode);
    }

    if(newNode->getValue() > currentNode->getValue()){
        if(currentNode->getRight() == nullptr){
            currentNode->setRight(newNode);
            newNode->setParent(currentNode);
        }else
            addNode(newNode, currentNode->getRight());
    }else{
        if(currentNode->getLeft() == nullptr){
            currentNode->setLeft(newNode);
            newNode->setParent(currentNode);
        }else
            addNode(newNode, currentNode->getLeft());
    }
    return newNode;
}

Node* Tree::getRoot(){
    return root;
}

void Tree::setRoot(Node* root){
    this->root = root;
}

int getHeight(Node* node) {
    if (node == nullptr) return 0;

    int leftHeight = getHeight(node->getLeft());
    int rightHeight = getHeight(node->getRight());

    int max = leftHeight > rightHeight ? leftHeight : rightHeight;

    return 1 + max;
}

int Tree::getBalanceFactor(Node* node) {
    if (node == nullptr) return 0;

    int leftHeight = getHeight(node->getLeft());
    int rightHeight = getHeight(node->getRight());

    return leftHeight - rightHeight;
}

Node* Tree::balance(Node* p) // балансировка узла p
{
    getHeight(p);

    if( getBalanceFactor(p) == 2 ){
        if( getBalanceFactor(p->getRight()) < 0 )
            p->setRight(rightRotate(p->getRight()));
        return leftRotate(p);
    }

    if( getBalanceFactor(p) == -2 ){
        if( getBalanceFactor(p->getLeft()) > 0  )
            p->setLeft(leftRotate(p->getLeft()));
        return rightRotate(p);
    }

    return p; // балансировка не нужна
}


// Функция для правого поворота поддерева с корнем в узле x
Node* Tree::rightRotate(Node* p) {
    Node* q = p->getLeft();
    p->setLeft( q->getRight() );
    q->setRight(p);
    return q;
}

Node* Tree::leftRotate(Node* p) {
    Node* q = p->getRight();
    q->setRight(p->getLeft());
    p->setLeft( q);

    return p;
}













