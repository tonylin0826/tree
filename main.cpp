#include <iostream>
#include "binarytree.hpp"

using namespace std;

int main() {

    cout << "asdsad" << endl;
    BinaryTree *tree = new BinaryTree();

    tree->pushNode(5);
    tree->pushNode(2);
    tree->pushNode(6);
    tree->pushNode(4);
    tree->pushNode(57);
    tree->pushNode(10);
    tree->pushNode(1);

    BinaryTree::traverse(tree->getRoot());

    tree->deleteNode(6);

    BinaryTree::traverse(tree->getRoot());

    delete [] tree;

    return 0;
}
