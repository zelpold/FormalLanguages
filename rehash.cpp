#include "rehash.h"
#include <QDebug>
Rehash::Rehash()
{
    searchCount = 0;
    for (int i = 0; i < HASHMAX; i++)
    {
        hashTable[i] = "";
    }
}
int Rehash::hashFunc(string str, int i)
{
    int hash;
    hash = ((str[0] + str[str.length()/2] + str[str.length()-1] - '0'*3)*i)%293;

    return hash;
}
bool Rehash::add(string str)
{
    int rehash_count = 0;
    while (true)
    {
        int hash = hashFunc(str, rehash_count);
        //qDebug() << hash;
        if (hashTable[hash] == "" || hashTable[hash]==str)
        {
            //qDebug() << "Yes";
            hashTable[hash] = str;
            return true;
        }
        rehash_count++;
    }
}
int Rehash::search(string str)
{
    int rehash_count = 0;
    while (true)
    {
        int hash = hashFunc(str, rehash_count);
        //qDebug() << hash;
        if (hashTable[hash] == "")
        {
            hashTable[hash] = str;
            return -1;
        }
        if (hashTable[hash]==str)
        {
            return rehash_count+1;
        }
        rehash_count++;
    }
}

void Rehash::fill(QList<string> list)
{
    for (auto i:list)
    {
        //qDebug() << i.c_str();
        add(i);
    }
}

void Rehash::clear()
{
    for (int i = 0; i < HASHMAX; i++)
    {
        hashTable[i] = "";
    }
}
