#include "hash.h"
#include <QDebug>
Hash::Hash()
{
    for (int i =0; i < HASHMAX - HASHMIN; i++)
    {
        hashmap[i] ="";
    }
}

int Hash::gethash(string str, int step)
{
    int hash;
    int H2 = HASHMAX - HASHMIN;
    //int H1 = H2/2 + 11;
    //int H1 = 121; //good
    int H1 = 137; // best
    //int H1 = 155; // the best

    hash = ((str[0] + str[str.length()/2-1] + str[str.length() - 1] - HASHMIN) + step*H1%H2)%H2;

    return hash;
}

bool Hash::add(string str)
{
    int rehash_step = 0;

    while(rehash_step<HASHMAX)
    {
        int hash = gethash(str, rehash_step);
        if (hashmap[hash] == "" || hashmap[hash]==str)
        {
            hashmap[hash] = str;
            return true;
        }
        qDebug() << hash << rehash_step;
        rehash_step++;

    }
    return false;
}

int Hash::search(string str)
{
    int rehash_step = 0;
    while (rehash_step < HASHMAX && hashmap[gethash(str, rehash_step)] != "")
    {
        if (hashmap[gethash(str, rehash_step)]==str)
        {
            return rehash_step+1;
        }
        rehash_step++;
    }

    return -1;
}

void Hash::fillhashmap(QList<string> list)
{
    for (auto i:list)
    {
        if (add(i) == false) break;
    }
}

void Hash::clear()
{
    for (int i =0; i < HASHMAX - HASHMIN; i++)
    {
        hashmap[i] ="";
    }
}
