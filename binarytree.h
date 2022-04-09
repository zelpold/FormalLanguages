#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <QList>
#include <string>


using namespace std;
class Node {
public:
    Node* left;
    Node* right;
    string name;

    Node (string);
    ~Node();
};

class BinaryTree
{
    Node*root;
public:
    BinaryTree();
    void add(string);
    void addNode(string&, Node *& root_node);
    bool search(string&, int &search_count, Node *root);

    void fillTree(QList<string> list);
    void clear();
};

#endif // BINARYTREE_H
