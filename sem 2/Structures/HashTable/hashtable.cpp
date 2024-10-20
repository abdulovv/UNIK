#include "hashtable.h"
#include "QMessageBox"

HashTable::HashTable(int size) {
    SIZE = size;
    count = 0;
    arr = new Item*[SIZE];

    for(int i = 0; i < size; i++){
        arr[i] = nullptr;
    }
}

int HashTable::hashFunction(int key){
    return key % SIZE;
}

void HashTable::add(Item* item){
    if(count <= SIZE){
        int key = item->key;
        int index = hashFunction(key);

        if(arr[index] != nullptr) QMessageBox::critical(nullptr, "", "Object was changed");
        arr[index] = item;
    count++;
    }else{
        QMessageBox::critical(nullptr, "", "Table is overload");
    }
}

bool HashTable::remove(int key){
    int index = hashFunction(key);

    if(arr[index] != nullptr){
        delete arr[index];
        arr[index] = nullptr;
        count--;
        QMessageBox::information(nullptr,"", "Object was removed");
        return true;
    }else
        QMessageBox::critical(nullptr,"", "Object wasn`t founed");

    return false;
}

QString HashTable::search(int key){
    QString res = nullptr;
    int index = hashFunction(key);

    if(arr[index] != nullptr){
        return arr[index]->value;
    }else
        QMessageBox::critical(nullptr,"", "Object wasn`t founed");

    return "";
}

QString HashTable::toQStringKeys(){
    QString res = "";
    for(int i = 0; i < SIZE; i++){
        if(arr[i] != nullptr){
            res += (QString::number(arr[i]->key) + "\n");
        }
    }
    return res;
}


QString HashTable::toQStringValues(){
    QString res = "";

    for(int i = 0; i < SIZE; i++){
        if(arr[i] != nullptr){
            res += (arr[i]->value + "\n");
        }
    }
    return res;
}















