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

TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == nullptr)
        return nullptr;
    if (root->val == val)
        return root;
    if (val < root->val)
        return searchBST(root->left, val);
    return searchBST(root->right, val);
}

TreeNode *searchBSTIter(TreeNode *root, int val) {
    TreeNode *curr = root;
    while (curr && curr->val != val) {
        if (val < curr->val)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return curr;
}

bool IsSameTree(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr)
        return root2 == nullptr;
    if (root1->val != root2->val)
        return false;
    return IsSameTree(root1->left, root2->left) && IsSameTree(root1->right, root2->right);
}

int main(int argc, char const *argv[])
{
    {
        cout << "=====Example1=====\n";
        TreeNode *root = new TreeNode(4);
        root->left = new TreeNode(2);
        root->right = new TreeNode(7);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(3);
        int val = 2;
        TreeNode *result = searchBSTIter(root, val);
        TreeNode *correct_result = root->left;
        assert(IsSameTree(result, correct_result));
        cout << "Example 1 passed!" << endl;
    }
    return 0;
}
