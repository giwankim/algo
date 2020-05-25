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

pair<TreeNode *, int> solve(int i, pair<int, int> range, vector<int> &preorder)
{
    if (i == (int)preorder.size())
        return {nullptr, i};
    if (preorder[i] < range.first || preorder[i] >= range.second)
        return {nullptr, i};

    TreeNode *root = new TreeNode(preorder[i]);

    auto left = solve(i + 1, make_pair(range.first, root->val), preorder);
    root->left = left.first;
    
    auto right = solve(left.second, make_pair(root->val, range.second), preorder);
    root->right = right.first;

    return {root, right.second};
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    return solve(0, make_pair(1, INF), preorder).first;
}

int main(int argc, char const *argv[])
{
    {
        vector<int> preorder{8, 5, 1, 7, 10, 12};
        TreeNode *result = bstFromPreorder(preorder);

        TreeNode *root = new TreeNode(8);
        root->left = new TreeNode(5);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(7);
        root->right = new TreeNode(10);
        root->right->right = new TreeNode(12);

        assert(result);
        assert(result->left);
        assert(result->left->left);
        assert(result->left->right);
        assert(result->right);
        assert(result->right->right);

        assert(result->val == root->val);
        assert(result->left->val == root->left->val);
        assert(result->left->left->val == root->left->left->val);
        assert(result->left->right->val == root->left->right->val);
        assert(result->right->val == root->right->val);
        assert(result->right->right->val == root->right->right->val);
    }
    return 0;
}
