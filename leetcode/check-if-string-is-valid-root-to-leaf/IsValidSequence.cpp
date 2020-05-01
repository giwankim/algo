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

bool check(int i, TreeNode *root, vector<int> &arr)
{
    if (root == nullptr)
        return false;
    if (root->val != arr[i])
        return false;
    if (i + 1 == arr.size())
        return root->left == nullptr && root->right == nullptr;
    return check(i + 1, root->left, arr) || check(i + 1, root->right, arr);
}

bool isValidSequence(TreeNode *root, vector<int> &arr)
{
    return check(0, root, arr);
}

int main(int argc, char const *argv[])
{
    {
        TreeNode *root = new TreeNode(0);
        root->left = new TreeNode(1);
        root->left->left = new TreeNode(0);
        root->left->left->right = new TreeNode(1);

        root->left->right = new TreeNode(1);
        root->left->right->left = new TreeNode(0);
        root->left->right->right = new TreeNode(0);

        root->right = new TreeNode(0);
        root->right->left = new TreeNode(0);

        vector<int> arr{0, 1, 0, 1};

        cout << isValidSequence(root, arr) << endl; // 1
    }

    {
        TreeNode *root = new TreeNode(0);
        root->left = new TreeNode(1);
        root->left->left = new TreeNode(0);
        root->left->left->right = new TreeNode(1);

        root->left->right = new TreeNode(1);
        root->left->right->left = new TreeNode(0);
        root->left->right->right = new TreeNode(0);

        root->right = new TreeNode(0);
        root->right->left = new TreeNode(0);

        vector<int> arr{0, 0, 1};

        cout << isValidSequence(root, arr) << endl; // 0
    }

    {
        TreeNode *root = new TreeNode(0);
        root->left = new TreeNode(1);
        root->left->left = new TreeNode(0);
        root->left->left->right = new TreeNode(1);

        root->left->right = new TreeNode(1);
        root->left->right->left = new TreeNode(0);
        root->left->right->right = new TreeNode(0);

        root->right = new TreeNode(0);
        root->right->left = new TreeNode(0);

        vector<int> arr{0, 1, 1};

        cout << isValidSequence(root, arr) << endl; // 0
    }

    return 0;
}
