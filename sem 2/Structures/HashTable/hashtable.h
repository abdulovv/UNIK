#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QString>

struct Item{
    int key;
    QString value;

    Item(int key, QString value){
        this->key = key;
        this->value = value;
    }

    bool equals(int key){
        return this->key == key;
    }
};


class HashTable{
public:
    HashTable(int size);
    void add(Item* item);
    bool remove(int key);
    QString search(int key);
    QString toQStringKeys();
    QString toQStringValues();
private:
    int SIZE;
    int count;
    Item** arr;
    int hashFunction(int key);
};

#endif // HASHTABLE_H
