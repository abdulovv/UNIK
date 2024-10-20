#ifndef DEQUE_H
#define DEQUE_H

#include "QString"

struct Item{
    int value;
    Item* next;

    Item(int value) {
        this->value = value;
        next = nullptr;
    }
};

class Deque{
public:
    Deque();
    void push_front(int value);
    void push_back(int value);
    void pop_front();
    void pop_back();
    Item* front();
    Item* back();
    bool isEmpty();
    int size();
    QString toQString();
private:
    Item* begin;
};

#endif // DEQUE_H
