#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>

class TreeNode {
public:
    TreeNode *leftChild;
    TreeNode *rightChild;
    TreeNode *parent;

    TreeNode() {
        leftChild = nullptr;
        parent = nullptr;
        rightChild = nullptr;
    }

    TreeNode(int value) {
        TreeNode();
        this->setValue(value);
    }

    int getValue() {
        return mValue;
    }

    void setValue(int v) {
        this->mValue = v;
    }
private:
    int mValue;
};

class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(int v);
    void pushNode(TreeNode *node);
    void pushNode(int value);

    void deleteNode(int value);

    TreeNode *getRoot() {
        return mRoot;
    }

    TreeNode *getNode(int value);

    static bool hasOneChild(TreeNode *node);
    static bool hasTwoChild(TreeNode *node);
    static void traverse(TreeNode *node);
    static bool isLeaf(TreeNode *node);
    static bool isRightChild(TreeNode *node);
    static bool isLeftChild(TreeNode *node);
private:
    TreeNode *mRoot;
};

#endif // BINARYTREE_HPP
