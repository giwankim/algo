#include "bits/stdc++.h"
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left_, TreeNode *right_) : val(x), left(left_), right(right_) {}
};

int widthOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    size_t ret = 0;
    queue<pair<TreeNode*, size_t>> q;
    q.emplace(root, 0);
    while (q.empty() == false)
    {
        size_t n = q.size();
        size_t left = q.front().second;
        for (size_t i = 0; i < n; ++i)
        {
            TreeNode *node = q.front().first;
            size_t index = q.front().second;
            q.pop();
            if (node->left)  q.emplace(node->left, 2 * index);
            if (node->right) q.emplace(node->right, 2 * index + 1);
            ret = max(ret, index - left + 1);
        }
    }
    return (int)ret;
}

int main(int argc, char const *argv[])
{
    {
        cout << "=====Example 1=====\n";
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(3);
        root->left->left = new TreeNode(5);
        root->left->right = new TreeNode(3);
        root->right = new TreeNode(2);
        root->right->right = new TreeNode(9);
        int result = widthOfBinaryTree(root);
        int correct_result = 4;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        // assert(nums == correct_result);
    }
    {
        cout << "=====Example 2=====\n";
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(3);
        root->left->left = new TreeNode(5);
        root->right = new TreeNode(2);
        int result = widthOfBinaryTree(root);
        int correct_result = 2;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        // assert(nums == correct_result);
    }
    {
        cout << "=====Example 3=====\n";
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(3);
        root->left->left = new TreeNode(5);
        root->right = new TreeNode(2);
        int result = widthOfBinaryTree(root);
        int correct_result = 2;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        // assert(nums == correct_result);
    }
    {
        cout << "=====Example 4=====\n";
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(3);
        root->left->left = new TreeNode(5);
        root->left->left->left = new TreeNode(6);
        root->right = new TreeNode(2);
        root->right->right = new TreeNode(9);
        root->right->right->right = new TreeNode(7);
        int result = widthOfBinaryTree(root);
        int correct_result = 8;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        // assert(nums == correct_result);
    }
    return 0;
}
