#include "hashtable.h"

HashTable::HashTable(int size) {
    SIZE = size;
    arr = new Item*[SIZE];

    for(int i = 0; i < size; i++){
        arr[i] = nullptr;
    }
}

int HashTable::hashFunction(int key){
    return key % SIZE;
}

void putItem(Item* firstItem, Item* newItem){
    Item* currentItem = firstItem;

    while(currentItem->next != nullptr){
        currentItem = currentItem->next;
    }

    currentItem->next = newItem;
}

void HashTable::add(Item* item){
    int key = item->key;
    int index = hashFunction(key);

    Item* firstItem = arr[index];

    if(firstItem == nullptr) arr[index] = item;
    else putItem(firstItem, item);
}

void HashTable::remove(int key){
    int index = hashFunction(key);

    Item* currentItem = arr[index];

    if(currentItem->next != nullptr){
        while(currentItem->next->equals(key)){
            currentItem = currentItem->next;
        }

        delete currentItem->next;

        currentItem->next = nullptr;
    }else{
        delete arr[index];
        arr[index] = nullptr;
    }
}

QString HashTable::search(int key){
    QString res = nullptr;
    int index = hashFunction(key);

    Item* currentItem = arr[index];

    if(currentItem != nullptr){
        while(currentItem->next->equals(key)){
            currentItem = currentItem->next;
        }

        res = currentItem->value;
    }

    return res;
}

QString HashTable::toQStringKeys(){
    QString res = "";
    for(int i = 0; i < SIZE; i++){
        res += (QString::number(arr[i]->key) + "\n");
    }
    return res;
}


QString HashTable::toQStringValues(){
    QString res = "";
    for(int i = 0; i < SIZE; i++){
        res += (arr[i]->value + "\n");
    }
    return res;
}















