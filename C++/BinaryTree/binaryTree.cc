#include <istream>

#include "binaryTree.h"


void binaryTree::destroy(bTreeNode* root) {
    if (NULL == root) {
        return;
    }

    if (root->hasLeft()) {
        destroy(root->left());
    } else if (root->hasRight()) {
        destroy(root->right());
    } else {
        delete root;
    }
}

binaryTree::~binaryTree() {
    destroy(root_);
}

void binaryTree::construct(bTreeNode* root, bTreeNode* node) {
    if (NULL == root || NULL == node) {
        std::cout << "binaryTree::construct: root or node equals to NULL" << std::endl;
        return;
    }

    if (node->value() < root->value()) {
        if (root->hasLeft()) {
            construct(root->left(), node);
        } else {
            root->setLeft(node); 
            return;
        }
    } else if (node->value() > root->value()) {
        if (root->hasRight()) {
            construct(root->right(), node);
        } else {
            root->setRight(node); 
            return;
        }
    } else {
        return; 
    }
}

void binaryTree::init(const std::vector<int>& input) {
    for (size_t i = 0; i < input.size(); ++i) {
        int value = input[i];
        bTreeNode* node = new bTreeNode(value);
        if (NULL == root_) {
            root_ = node;
            continue;
        } else {
            construct(root_, node); 
        }
    }
}

void  binaryTree::goThroughTree(bTreeNode* root) {
    if (root == NULL) {
        return;
    } 

    if (root->hasLeft()) {
        goThroughTree(root->left());
    }

    std::cout << root->value() << "\t";

    if (root->hasRight()) {
        goThroughTree(root->right());
    }
}

void  binaryTree::goThroughTree() {
    if (NULL == root_) {
        std::cout << "The tree is empty" << std::endl;
        return;
    }

    goThroughTree(root_);

    std::cout << std::endl;
}
