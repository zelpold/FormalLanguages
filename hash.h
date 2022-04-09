#pragma once
#include <QList>
#include <QString>

#ifndef REHASH_H
#define REHASH_H

#endif // REHASH_H
const int HASHMAX = 398;
const int HASHMIN = 145;
using namespace std;
class Hash
{
    string hashmap[HASHMAX-HASHMIN]={""};

    int searchCount;
public:
    //Hash();
    int gethash(string str, int i);
    bool add(string);
    int search(string);
    void fillhashmap(QList<string> list);
    void clear();

private:

};
