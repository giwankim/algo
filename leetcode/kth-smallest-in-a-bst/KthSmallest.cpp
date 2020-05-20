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

void inorder(TreeNode *root, vector<int> &vec)
{
    if (root == nullptr)
        return;
    inorder(root->left, vec);
    vec.push_back(root->val);
    inorder(root->right, vec);
}

int kthSmallest(TreeNode *root, int k)
{
    vector<int> vec;
    inorder(root, vec);
    return vec[k - 1];
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
