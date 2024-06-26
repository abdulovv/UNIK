#ifndef STACK_H
#define STACK_H

#include <QString>
#include <QMessageBox>

struct Item{
    int value;
    Item* next;
    Item* prev;

    Item(){
        next = nullptr;
        prev = nullptr;
    }

    Item(int value, Item* prev){
        this->value = value;
        this->prev = prev;
        next = nullptr;
    }

    Item(int value){
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};

class Stack{
private:
    Item* last;
public:
    Stack();
    void push(int value);
    void pop();
    Item* top();
    bool isEmpty();
    int size();
};

#endif // STACK_H
