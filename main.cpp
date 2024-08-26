#include <iostream>


#include "BSTIterator.hpp"

using namespace std;

int main() {
//    TreeNode* root = new TreeNode(3);
//    TreeNode* node1 = new TreeNode(1);
//    TreeNode* node2 = new TreeNode(2);
//    TreeNode* node3 = new TreeNode(3);
//    TreeNode* node4 = new TreeNode(4);
//    TreeNode* node5 = new TreeNode(5);
//    TreeNode* node6 = new TreeNode(6);
//    TreeNode* node7 = new TreeNode(7);
//    TreeNode* node8 = new TreeNode(8);
//    TreeNode* node9 = new TreeNode(9);
//    TreeNode* node0 = new TreeNode(0);
//    TreeNode* node15 = new TreeNode(15);
//    TreeNode* node20 = new TreeNode(20);
//
//    node4->left = node2;
//    node4->right = node6;
//    node2->left = node1;
//    node2->right = node3;
    int n =5;
    vector<vector<int>> edges = {{2,4},{0,2},{0,4}};
    vector<int> ans = shortestDistanceAfterQueries(n, edges);
    for(auto ele: ans){
        printf("%d",ele);
    }
    return 0;
}
