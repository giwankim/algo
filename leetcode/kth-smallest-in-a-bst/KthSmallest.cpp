#include "bits/stdc++.h"
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *_left, TreeNode *_right) : val(x), left(_left), right(_right) {}
};

pair<bool, int> inorder(TreeNode *root, int &k)
{
    if (root == nullptr)
        return make_pair(false, -1);
    auto left = inorder(root->left, k);
    if (left.first)
        return left;
    if (--k == 0)
        return make_pair(true, root->val);
    return inorder(root->right, k);
}

int kthSmallest(TreeNode *root, int k)
{
    return inorder(root, k).second;
}

int main(int argc, char const *argv[])
{
    {
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(1);
        root->left->right = new TreeNode(2);
        root->right = new TreeNode(4);
        cout << kthSmallest(root, 1) << endl; // 1
    }
    {
        TreeNode *root = new TreeNode(5);
        root->left = new TreeNode(3);
        root->left->left = new TreeNode(2);
        root->left->right = new TreeNode(4);
        root->left->left->left = new TreeNode(1);
        root->right = new TreeNode(6);
        cout << kthSmallest(root, 3) << endl; // 3
    }
    return 0;
}
