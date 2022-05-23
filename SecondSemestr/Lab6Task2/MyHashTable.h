#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H
#include "stack.h"
#include <cmath>
#include <QString>
#include <QTextStream>
#include <QStack>


namespace stlMax {

class MyHashTable
{
    int capacity;
    int randq;
    Stack<int> *table;
public:

    MyHashTable(int V = 50);
    void insertItem(int key, int data);
    void removeItem(int key);
    QString printTable();
    bool checkPrime(int n) {
        if (n == 1 || n == 0) {
            return 0;
        }
        for (int i = 2; i < sqrt(n) + 1; i++) {
            if (n % i == 0) {
                return 0;
            }
        }
        return true;
    }

    int getPrime(int n) {
        if (n % 2 == 0) {
            n++;
        }
        while (!checkPrime(n)) {
            n += 2;
        }
        return n;
    }

    int hashFunction(int key) {
    return (key % capacity);
    }


};

MyHashTable::MyHashTable(int c)
{
    randq = rand() % 10;
    int size = getPrime(c + randq);
    this->capacity = size;
    table = new Stack<int>[capacity];
}

void MyHashTable::insertItem(int key, int data)
{
    int index = hashFunction(hashFunction(key) + capacity + randq);
    table[index].Push(data);
}

void MyHashTable::removeItem(int key)
{
    int index = hashFunction(hashFunction(key) + capacity + randq);
    if (table[index].Size() == 0){
        return;
    }
    table[index].Pop();
}

QString MyHashTable::printTable()
{
    QString text;
    QTextStream ans(&text);
    for (int i = 0; i < capacity; i++) {
        ans <<"table[" << i << "]";
        if (!table[i].isEmpty()) ans << " --> " << table[i].Top();
        ans << '\n';
    }
    return text;
}

}
#endif // MYHASHTABLE_H
