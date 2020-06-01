#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *_left, TreeNode *_right) : val(x), left(_left), right(_right) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    TreeNode *tmp = root->right;
    root->right = invertTree(root->left);
    root->left = invertTree(tmp);
    return root;
}

int main(int argc, char const *argv[])
{
    {
        TreeNode *root = new TreeNode(4);
        root->left = new TreeNode(2);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(3);
        root->right = new TreeNode(7);
        root->right->left = new TreeNode(6);
        root->right->right = new TreeNode(9);
        TreeNode *ans = invertTree(root);
        assert (ans && ans->val == 4);
        assert (ans->left && ans->left->val == 7);
        assert (ans->left->left && ans->left->left->val == 9);
        assert (ans->left->right && ans->left->right->val == 6);
        assert (ans->right && ans->right->val == 2);
        assert (ans->right->left && ans->right->left->val == 3);
        assert (ans->right->right && ans->right->right->val == 1);
    }
    return 0;
}
 