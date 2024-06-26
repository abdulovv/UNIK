#include "deque.h"
#include "QMessageBox"

Deque::Deque() {
    begin = nullptr;
}

Item* Deque::back(){
    Item* end = begin;

    while(end->next != nullptr){
        end = end->next;
    }

    return end;
}

void Deque::push_front(int value){
    Item* newItem = new Item(value);
    if(!isEmpty()){
        newItem->next = begin;
    }

    begin = newItem;
}

void Deque::push_back(int value){
    Item* newItem = new Item(value);
    if(!isEmpty()){
        Item* end = back();

        end->next = newItem;
    }else{
        begin = newItem;
    }
}

void Deque::pop_front(){

    if(isEmpty()){
        QMessageBox::critical(nullptr, "", "Deque is empty");
    }else if(begin->next == nullptr){
        delete begin;
        begin = nullptr;
    }else{
        Item* newBegin = begin->next;
        delete begin;

        begin = newBegin;
    }
}

void Deque::pop_back(){
    if(isEmpty()){
        QMessageBox::critical(nullptr, "", "Deque is empty");
    }else if(begin->next == nullptr){
        delete begin;
        begin = nullptr;
    }else{
        Item* newEnd = begin;

        while(newEnd->next->next != nullptr){
            newEnd = newEnd->next;
        }

        delete newEnd->next;

        newEnd->next = nullptr;
    }
}

Item* Deque::front(){
    return begin;
}

bool Deque::isEmpty(){
    return begin == nullptr;
}

int Deque::size(){
    if(!isEmpty()){
        int size = 1;
        Item* currentItem = begin;

        while(currentItem->next != nullptr){
            currentItem = currentItem->next;
            size++;
        }
        return size;
    }
    return 0;
}

QString Deque::toQString(){
    QString res = "";

    if(!isEmpty()){
        Item* currentItem = begin;

        res+= (" " + QString::number(currentItem->value) + " ");

        while(currentItem->next != nullptr){
            currentItem = currentItem->next;
            res+= (" " + QString::number(currentItem->value) + " ");
        }
    }

    return res;
}


























