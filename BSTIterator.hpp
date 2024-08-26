//
// Created by admin on 2024/7/17.
//

#ifndef BST_BSTITERATOR_HPP
#define BST_BSTITERATOR_HPP
#include "binaryTree.hpp"

class BSTIterator {
public:
    BSTIterator(TreeNode* root);
    int next();
    bool hasNext();
private:
    std::stack<TreeNode*> nodes;
};

#endif //BST_BSTITERATOR_HPP
