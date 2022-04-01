#pragma once
#include <QList>
#include <QString>

#ifndef REHASH_H
#define REHASH_H

#endif // REHASH_H
const int HASHMAX = 300;
using namespace std;
class Rehash
{
    string hashTable[HASHMAX];

    int searchCount;
public:
    Rehash();
    int hashFunc(string str, int i);
    bool add(string);
    int search(string);
    void fill(QList<string> list);
    void clear();

private:

};
