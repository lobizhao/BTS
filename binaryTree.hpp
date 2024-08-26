#ifndef BST_BINARYTREE_H
#define BST_BINARYTREE_H

#endif //BST_BINARYTREE_H
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <set>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

void preOrfer(TreeNode* root,std::vector<int>& nodes);
void inOrder(TreeNode* root,std::vector<int>& nodes);
void postOrder(TreeNode* root,std::vector<int>& nodes);
void levelOrder(TreeNode* root, std::vector<int>& nodes);
void flatten(TreeNode* root);
std::string getDirections(TreeNode* root, int startValue, int destValue);

//lowest common ancestor
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q);

std::vector<TreeNode*> delNodes(TreeNode* root, std::vector<int>& to_delete);

int countPairs(TreeNode* root, int distance);

void printVector(std::vector<int> nums);
int getMinimumDifference(TreeNode* root);
std::vector<std::vector<int>> levelOrder(TreeNode* node);
std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root);
int kthSmallest(TreeNode* root, int k);
int secondMinimum(int n, std::vector<std::vector<int>>& edges, int time, int change);
std::vector<int> shortestDistanceAfterQueries(int n, std::vector<std::vector<int>>& queries);