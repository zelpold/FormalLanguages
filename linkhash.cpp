#include "linkhash.h"
#include <QDebug>
LinkHash::LinkHash()
{
    for (int i = 0; i < HASHMAX; i++)
    {
        hashTab[i] = nullptr;
    }
    Node * node = new Node;
    node->name = "";
    freePtr = node;
    freePtr->node = nullptr;
}

int LinkHash::hashFunc(string str)
{
    int hash;
    hash = (str[0]
            + str[str.length()/2]
            + str[str.length()-1]
            - '0'*3)
            % 293;
    return hash;
}

bool LinkHash::add(string str)
{
    int hash = hashFunc(str);
    qDebug() << hash << str.c_str();
    if (hashTab[hash] == nullptr)
    {
        hashTab[hash] = new NodePtr();
        freePtr->name = str;
        hashTab[hash]->node=freePtr;
        Node * node = new Node;
        node->name = "";
        freePtr = node;
        freePtr->node = nullptr;
        qDebug() << hash << ' ' <<  hashTab[hash]->node->name.c_str();
        return true;

    }
    else
    {

        Node* next = hashTab[hash]->node;
        int count = 0;

        while (next->node!=nullptr)
        {
            qDebug() << count << next->node->name.c_str();
            count++;
            if (next->name == str) return true;
            next = next->node;
        }

        freePtr->name = str;
        next->node = freePtr;
        qDebug() << count << next->node->name.c_str();
        Node * node = new Node;
        freePtr = node;
        freePtr->node = nullptr;
        return true;
    }
}

int LinkHash::search(string str)
{
    int count = 0;
    int hash = hashFunc(str);
    qDebug() << hash << ' ' << str.c_str();

    if (hashTab[hash]->node !=nullptr)
    {

        Node *node = hashTab[hash]->node;
        while (node != nullptr)
        {
            count++;
            qDebug() << node->name.c_str();
            if (node->name == str)
            {
                return count;
            }
            node = node->node;
        }
        return -1;
    }
    return -1;
}

void LinkHash::fill(QList<string> list_id)
{
    for (auto i:list_id)
    {
        add(i);
    }
}

void LinkHash::clear()
{
    for (int i=0; i < HASHMAX; i++)
    {
        if (hashTab[i]!=nullptr)
        {
            Node * node = hashTab[i]->node;
            while (node != nullptr)
            {
                Node *deleted = node;
                node = node->node;
                delete deleted;
            }
            delete  hashTab[i];
        }
        hashTab[i]=nullptr;
    }
}

LinkHash::~LinkHash()
{
    clear();
    delete freePtr;
}


