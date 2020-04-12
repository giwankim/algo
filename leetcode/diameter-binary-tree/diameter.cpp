#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

pair<int, int> dfs(TreeNode* root)
{
    if (root == nullptr) return make_pair(0, 0);
    auto left = dfs(root->left);
    auto right = dfs(root->right);

    int depth = max(left.second, right.second) + 1;
    int diameter = max({left.second + right.second, left.first, right.first});
    return make_pair(diameter, depth);
}

int diameterOfBinaryTree(TreeNode* root)
{
    if (root == nullptr) return 0;
    auto result = dfs(root);
    return result.first;
}

int main(int argc, char const *argv[])
{
    /* code */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << diameterOfBinaryTree(root) << "\n";
    // cout << dfs(root->left).first << "," << dfs(root->left).second << "\n";
    return 0;
}
