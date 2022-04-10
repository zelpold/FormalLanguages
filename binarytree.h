#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <QList>
#include <string>


using namespace std;
struct Node {
public:
    Node* left;
    Node* right;
    string name;

    Node (string);

};

class BinaryTree
{
    Node*root;
public:
    BinaryTree();

    void add(string);
    void addNode(string, Node *& root_node);
    bool search(string, int &search_count , Node *root);
    int search(string str);
    void fillTree(QList<string> list);
    void clear();
    void deleteNode(Node* &node);
};

#endif // BINARYTREE_H
