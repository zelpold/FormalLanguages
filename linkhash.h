#pragma once
#ifndef LinkHash_H

#define LinkHash_H
#include "hash.h"
#include <QString>


using namespace std;
struct Node
{
    string name;
    Node* node = node;
};

struct NodePtr
{
    Node* node =node;
};

class LinkHash
{
    Node * head= nullptr;
    Node * freePtr = nullptr;
    NodePtr * hashTab[HASHMAX];
public:
     LinkHash();
     int hashFunc(string str);
     bool add(string);
     int search(string);
     void fill(QList<string> list_id);
     void clear();
     ~LinkHash();
private:

};

#endif // LinkHash_H
