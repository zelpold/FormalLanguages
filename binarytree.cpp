#include "binarytree.h"

BinaryTree::BinaryTree()
{
    root = nullptr;
}

void BinaryTree::fillTree(QList<string> list)
{
    for (auto i: list)
    {
        addNode(i, root);
    }
}

void BinaryTree::addNode(string& str, Node *&root_node)
{
    if (root_node == nullptr) root_node = new Node (str);
    if (root_node->name > str) addNode(str, root_node->right);
    else if (root_node->name == str) return;
    else addNode(str, root_node->left);
}

bool BinaryTree::search(string &str, int &search_count, Node * root_node)
{
    if (root_node == nullptr) return false;
    if (root_node->name == str) return true;
    search_count++;
    if (root_node->name > str) return search(str, search_count, root_node->right);
    else search(str, search_count, root_node->left);
}

Node::Node(string str)
{
    name    = str;
    right   = nullptr;
    left    = nullptr;
}
