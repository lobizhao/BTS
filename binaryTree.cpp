//
// Created by admin on 2024/7/9.
//

#include <unordered_set>
#include "binaryTree.hpp"

using namespace std;

void preOrfer(TreeNode* root,vector<int>& nodes){
    if(root == nullptr){
        return;
    }
    nodes.push_back(root->val);
    preOrfer(root->left, nodes);
    preOrfer(root->right,nodes);
}

void inOrder(TreeNode* root,std::vector<int>& nodes){
    if(root == nullptr){
        return;
    }
    inOrder(root->left, nodes);
    nodes.push_back(root->val);
    inOrder(root->right, nodes);
}

void postOrder(TreeNode* root,std::vector<int>& nodes){
    if(root == nullptr){
        return;
    }
    postOrder(root->left,nodes);
    postOrder(root->right,nodes);
    nodes.push_back(root->val);
}

void levelOrder(TreeNode* root, std::vector<int>& nodes){
    if(root == nullptr){
        return;
    }
    queue<TreeNode*> que;
    que.push(root);

    while (!que.empty()){
        TreeNode* current = que.front();
        nodes.push_back(current->val);
        que.pop();

        if(current->left != nullptr){
            que.push(current->left);
        }
        if(current->right != nullptr){
            que.push(current->right);
        }
    }
}


void flatten(TreeNode* root){
    if(root == nullptr){
        return;
    }

    TreeNode* current = root;
    while (current != nullptr){
        if(current->left){
            TreeNode* prve = root->left;
            while (prve->right != nullptr){
                prve = prve->right;
            }

            prve->right = current->right;
            current->right = current->left;
            current->left = nullptr;
        }

        current = current->right;
    }
}

void printVector(std::vector<int> nums){
    for(auto ele: nums){
        cout<< ele << " ";
    }
    cout << endl;
}

TreeNode* findLCA(TreeNode* root, int sValue, int dValue){
    if(root == nullptr || root->val == sValue || root->val == dValue){
        return root;
    }

    TreeNode* left = findLCA(root->left, sValue, dValue);
    TreeNode* right = findLCA(root->right, sValue, dValue);

    if(left && right){
        return root;
    }

    return left? left:right;

}

bool nodeGetPath(TreeNode* root, int value, string& path){
    if(!root){
        return false;
    }
    if(root->val == value){
        return true;
    }
    path.push_back('L');
    if(nodeGetPath(root->left, value, path)){
        return true;
    }
    path.pop_back();

    path.push_back('R');
    if(nodeGetPath(root->right, value, path)){
        return true;
    }
    path.pop_back();

    return false; //????????? what?

}



string getDirections(TreeNode* root, int startValue, int destValue) {
    TreeNode* lca = findLCA(root, startValue, destValue);

    string toS = "";
    string toE = "";

    nodeGetPath(lca, startValue, toS);
    nodeGetPath(lca, destValue, toE);

    for(auto& ele: toS){
        ele = 'U';
    }

    return toS + toE;

}
//for just binary search tree like the middle one is root, smaller number on the left, larger number on the right
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root->val > p->val && root->val > q->val){
        return lowestCommonAncestor(root->left, p, q);
    }else if(root->val < p->val && root->val < q->val){
        return lowestCommonAncestor(root->right, p, q);
    }else{
        return root;
    }
}
//for normally binary trees just randomly trees

TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root== nullptr || root == p || root == q){
        return root;
    }

    TreeNode* left = lowestCommonAncestor2(root->left, p, q);
    TreeNode* right = lowestCommonAncestor2(root->right, p, q);

    if(left && right){
        return root;
    }
    if(left){
        return left;
    } else{
        return right;
    }
}

TreeNode* dfs(TreeNode* root, unordered_set<int>& list, vector<TreeNode*>& ans){
    if(root == nullptr){
        return nullptr;
    }

    root->left = dfs(root->left, list, ans);
    root->right = dfs(root->right, list, ans);

    if(list.contains(root->val)){
        if(root->left){
            ans.push_back(root->left);
        }
        if(root->right){
            ans.push_back(root->right);
        }

        root = nullptr;
        return nullptr;
    }

    return root;
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> ans;
    unordered_set<int> deleteList(to_delete.begin(), to_delete.end());

    root = dfs(root, deleteList,ans);

    if(root){
        ans.push_back(root);
    }
    return ans;
}
int ans =0;
vector<int> pairDFS(TreeNode* root, int distance){
    vector<int> pairs(distance,0);
    if(root == nullptr){
        return pairs;
    }

    if(root->left == nullptr && root->right == nullptr){
        pairs[1] = 1;
        return pairs;
    }

    auto left = pairDFS(root->left, distance);
    auto right = pairDFS(root->right, distance);

    for(int i = 0; i<= distance; i++){
        for(int j =0; j<= distance; j++){
            if(i +j <= distance){
                ans += left[i] * right[j];
            }
        }
    }

    for(int i =distance; i>0; i--){
        pairs[i] = left[i -1] + right[i -1];
    }

    return pairs;
}

int countPairs(TreeNode* root, int distance){
    pairDFS(root, distance);
    return ans;
}
void inOrder_BST(TreeNode* root, vector<int>& nodes){
    if(root == nullptr){
        return;
    }

    inOrder_BST(root->left,nodes);
    nodes.push_back(root->val);
    inOrder_BST(root->right, nodes);

}

int getMinimumDifference(TreeNode* root) {
    vector<int> nodes;

    inOrder_BST(root, nodes);
    int minDiffer = INT_MAX;
    for(int i=1; i<nodes.size(); i++){
        minDiffer = min(minDiffer, nodes[i]-nodes[i-1]);
    }
    return minDiffer;

}

vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> ans;
    if(root == nullptr){
        return ans;
    }

    queue<TreeNode*> que;
    que.push(root);

    while (!que.empty()){
        int leveSize = que.size();
        vector<int> levelValue;

        for(int i=0; i< leveSize; i++){
            TreeNode* node = que.front();
            que.pop();

            levelValue.push_back(node->val);

            if(node->left != nullptr){
                que.push(node->left);
            }
            if(node->right != nullptr){
                que.push(node->right);
            }
        }
        ans.push_back(levelValue);
    }

    return ans;
}
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == nullptr){
        return ans;
    }

    queue<TreeNode*> que;
    que.push(root);
    int level =0;

    while (!que.empty()){
        int leveSize = que.size();
        vector<int> curLeve(leveSize);

        for(int i=0; i< leveSize; i++){
            TreeNode* curNode = que.front();
            que.pop();

            int index =0;
            if(level %2 ==0){
                index = i;
            }else{
                index = leveSize-1 -i;
            }
             curLeve[index]= curNode->val;

            if(curNode->left){
                que.push(curNode->left);
            }
            if(curNode->right){
                que.push(curNode->right);
            }
        }
        ans.push_back(curLeve);
        level++;
    }

    return ans;
}

void kthInorder(TreeNode* root, vector<int>& node){
    if(root == nullptr){
        return;
    }
    kthInorder(root->left,node);
    node.push_back(root->val);
    kthInorder(root->right, node);

}
int kthSmallest(TreeNode* root, int k){
    vector<int> nodes;
    kthInorder(root, nodes);
    return nodes[k-1];
}

int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    unordered_map<int, vector<int>> adj;
    vector<pair<int, int>> vis(n+1, {0,0});

    queue<pair<int, int>> que;
    for(auto ele:edges){
        adj[ele[0]].push_back(ele[1]);
        adj[ele[1]].push_back(ele[0]);
    }

    que.push({1,0});
    vis[1] = {1,0};
    while (true){
        auto [node, arrive] = que.front();
        que.pop();

        bool needWait = (arrive /change)&1; //???what??
        int waitTime = needWait?((arrive/change) +1) * change - arrive: 0;
        int nextTime = arrive+waitTime + time;
        for(auto next :adj[node]){
            if(vis[next].first <2 && vis[next].second != nextTime){
                que.push({next, arrive+waitTime+time});
                vis[next].first +=1;
                vis[next].second = nextTime;
                if(next == n && vis[next].first ==2){
                    return nextTime;
                }
            }
        }
    }
    return -1;
}
int querBsf(int n, vector<vector<int>> adj){
    vector<int> distance(n, INT_MAX);
    queue<int> que;
    distance[0] = 0;
    que.push(0);
    while (!que.empty()){
        int node = que.front();
        que.pop();
        for(auto iter: adj[node]){
            if(distance[node] +1 < distance[iter]){
                distance[iter] = distance[node] +1;
                que.push(iter);
            }
        }
    }
    return distance[n-1] == INT_MAX? -1:distance[n-1];

}

vector<int> shortestDistanceAfterQueries(int n, std::vector<std::vector<int>>& queries){
    vector<int> ans;
    vector<vector<int>> adj(n);
    for(int i=0; i < n-1; i++){
        adj[i].push_back(i+1);
    }

    for(auto ele: queries){
        adj[ele[0]].push_back(ele[1]);
        int minDis = querBsf(n, adj);
        ans.push_back(minDis);
    }

    return ans;
}