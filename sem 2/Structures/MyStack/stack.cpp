#include "stack.h"

Stack::Stack() {
    last = nullptr;
}

void Stack::push(int value){
    Item* newItem = (last == nullptr ? new Item(value) : new Item(value, last));

    if(last == nullptr){
        last = newItem;
    }else{
        last->next = newItem;
        last = newItem;
    }
}

void Stack::pop(){
    if(last->prev != nullptr){
        Item* newLast = last->prev;
        delete last;

        last = newLast;
        last->next = nullptr;
    }else{
        delete last;
        last = nullptr;
    }
}

Item* Stack::top(){
    return last;
}

bool Stack::isEmpty(){
    return last == nullptr;
}

int Stack::size(){
    Item* current = last;
    int size;

    if(current == nullptr) return 0;
    else size = 1;

    while(current->prev != nullptr){
        current = current->prev;
        size++;
    }

    return size;
}








