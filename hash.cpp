#include "hash.h"

int Hash::gethash(string str, int step)
{
    int hash;
    int H2 = HASHMAX - HASHMIN;
    int H1 = H2/2 + 9;
    hash = ((str[0] + str[str.length()/2-1] + str[str.length()] + str.length() - HASHMIN) + step*H1%H2)%H2;
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
    for (auto i: hashmap)
    {
        i="";
    }
}
