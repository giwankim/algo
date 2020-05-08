#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs(TreeNode* root, int depth, int prev, unordered_map<int, pair<int, int>>& table) {
    if (root == nullptr) return;
    table[root->val] = make_pair(depth, prev);
    dfs(root->left, depth+1, root->val, table);
    dfs(root->right, depth+1, root->val, table);
}

bool isCousins(TreeNode* root, int x, int y) {
    unordered_map<int, pair<int, int>> table;
    dfs(root, 0, -1, table);
    auto left = table[x];
    auto right = table[y];
    return left.first == right.first && left.second != right.second;
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    cout << isCousins(root, 4, 3) << endl;
    return 0;
}
