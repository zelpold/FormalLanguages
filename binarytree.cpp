#include "binarytree.h"
#include <QDebug>
BinaryTree::BinaryTree()
{
    root = nullptr;
}

void BinaryTree::fillTree(QList<string> list)
{
    for (const auto &i: list) addNode(i, root);
}

void BinaryTree::clear()
{
    deleteNode(root);
}

void BinaryTree::deleteNode(Node *&node)
{
    if (node != nullptr)
    {
        deleteNode(node->left);
        deleteNode(node->right);
        qDebug() << node->name.c_str();
        delete node;
        node = nullptr;
    }
}

void BinaryTree::addNode(string str, Node *&root_node)
{
    if (root_node == nullptr) root_node = new Node (str);
    if (root_node->name > str) addNode(str, root_node->right);
    else if (root_node->name == str) return;
    else addNode(str, root_node->left);
}

bool BinaryTree::search(string str, int &search_count, Node * root_node)
{
    qDebug() << search_count << str.c_str() << root_node->name.c_str();
    if (root_node == nullptr) return false;
    if (root_node->name == str) return true;
    search_count++;
    if (root_node->name > str) return search(str, search_count, root_node->right);
    return search(str, search_count, root_node->left);
}

int BinaryTree::search(string str)
{
    int count = 1;
    if (search(str, count, root))return count;
    return -1;
}

Node::Node(string str)
{
    name    = str;
    right   = nullptr;
    left    = nullptr;
}
