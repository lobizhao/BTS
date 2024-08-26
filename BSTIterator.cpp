//
// Created by admin on 2024/7/17.
//

#include "BSTIterator.hpp"


BSTIterator::BSTIterator(TreeNode* root) {
    TreeNode* node = root;
    while (node != nullptr){
        nodes.push(node);
        node = node->left;
    }
}

int BSTIterator::next() {
    int ans = nodes.top()->val;
    TreeNode* next = nodes.top()->right;
    nodes.pop();
    while ( next != nullptr){
        nodes.push(next);
        next = next->left;
    }
    return ans;
}

bool BSTIterator::hasNext() {
    if(!nodes.empty()){
        return true;
    } else{
        return false;
    }
}
