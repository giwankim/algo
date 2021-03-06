#include "bits/stdc++.h"
using namespace std;
#define INF 1000000000

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *_left, TreeNode *_right) : val(x), left(_left), right(_right) {}
};

pair<int, int> dfs(TreeNode *root)
{
    if (root == nullptr)
        return make_pair(-INF, 0);
    auto left = dfs(root->left);
    auto right = dfs(root->right);
    int left_gain = max(0, left.second);
    int right_gain = max(0, right.second);
    int sum = root->val + left_gain + right_gain;
    return make_pair(max({left.first, right.first, sum}), root->val + max(left_gain, right_gain));
}

int maxPathSum(TreeNode *root)
{
    return dfs(root).first;
}

int main(int argc, char const *argv[])
{
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        cout << maxPathSum(root) << "\n";  // 6
    }
    {
        TreeNode *root = new TreeNode(-10);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);
        cout << maxPathSum(root) << "\n";  // 42
    }
    {
        TreeNode *root = new TreeNode(-3);
        cout << maxPathSum(root) << "\n";  // -3
    }
    {
        TreeNode *root = new TreeNode(5);
        root->left = new TreeNode(4);
        root->left->left = new TreeNode(11);
        root->left->left->left = new TreeNode(7);
        root->left->left->right = new TreeNode(2);
        root->right = new TreeNode(8);
        root->right->left = new TreeNode(13);
        root->right->right = new TreeNode(4);
        root->right->right->right = new TreeNode(1);
        cout << maxPathSum(root) << "\n";  // 48
    }
    return 0;
}
