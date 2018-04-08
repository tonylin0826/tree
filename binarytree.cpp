#include "binarytree.hpp"

BinaryTree::BinaryTree() {
    mRoot = nullptr;
}

BinaryTree::BinaryTree(int rootValue) {
    mRoot = new TreeNode(rootValue);
}

TreeNode* BinaryTree::getNode(int value) {
    TreeNode *current = mRoot;
    while (current != nullptr) {
        // go to right
        if (value > current->getValue()) {
            std::cout << "to r" << std::endl;
            current = current->rightChild;
        }
        // go to left
        else if (value < current->getValue()) {
            std::cout << "to l" << std::endl;
            current = current->leftChild;
        } else {
            std::cout << "f" << std::endl;
            return current;
        }
    }

    return nullptr;
}

bool BinaryTree::hasOneChild(TreeNode *node) {
    return (node->leftChild != nullptr && node->rightChild == nullptr) || (node->leftChild == nullptr && node->rightChild != nullptr);
}

bool BinaryTree::hasTwoChild(TreeNode *node) {
    return node->leftChild != nullptr && node->rightChild != nullptr;
}

bool BinaryTree::isLeaf(TreeNode *node) {
    return node->leftChild == nullptr && node->rightChild == nullptr;
}

bool BinaryTree::isLeftChild(TreeNode *node) {
    TreeNode *parent = node->parent;
    if (parent == nullptr) {
        return false;
    }

    if (parent->leftChild != nullptr && parent->leftChild == node) {
        return true;
    }

    return false;
}

bool BinaryTree::isRightChild(TreeNode *node) {
    TreeNode *parent = node->parent;
    if (parent == nullptr) {
        return false;
    }

    if (parent->rightChild != nullptr && parent->rightChild == node) {
        return true;
    }

    return false;
}

void BinaryTree::traverse(TreeNode *node) {
    if (node == nullptr) return;

    std::cout << node->getValue() << std::endl;
    traverse(node->leftChild);
    traverse(node->rightChild);
}

void BinaryTree::deleteNode(int value) {
    // 3 cases: leaf, 1 child and 2 children
    TreeNode *current = BinaryTree::getNode(value);

    if (current == nullptr) {
        std::cout << "Cannot find " << value << " in tree" << std::endl;
        return;
    }

    if (BinaryTree::isLeaf(current)) {
        // Remove current
        if (BinaryTree::isLeftChild(current)) {
            current->parent->leftChild = nullptr;
            delete [] current;
        } else {
            current->parent->rightChild = nullptr;
            delete [] current;
        }
    }
    // 1 child case
    else if (BinaryTree::hasOneChild(current)) {

        TreeNode *child = current->leftChild == nullptr ? current->rightChild : current->leftChild;

        // Remove current and attach child
        if (BinaryTree::isLeftChild(current)) {
            current->parent->leftChild = child;
            delete [] current;
        } else {
            current->parent->rightChild = child;
            delete [] current;
        }
    }
    // 2 children case
    else if (BinaryTree::hasTwoChild(current)) {

    }
}

void BinaryTree::pushNode(int value) {
    this->pushNode(new TreeNode(value));
}

void BinaryTree::pushNode(TreeNode *node) {

    if (mRoot == nullptr) {
        mRoot = node;
        return;
    }

    TreeNode *current = mRoot;
    while (current != nullptr) {

        // go to right
        if (node->getValue() > current->getValue()) {
            if (current->rightChild == nullptr) {
                current->rightChild = node;
                node->parent = current;
            } else {
                current = current->rightChild;
            }
        }
        // go to left
        else if (node->getValue() < current->getValue()) {
            if (current->leftChild == nullptr) {
                current->leftChild = node;
                node->parent = current;
            } else {
                current = current->leftChild;
            }
        } else {
            break;
        }
    }
}
