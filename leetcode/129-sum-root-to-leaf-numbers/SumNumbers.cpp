#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* _left, TreeNode* _right) : val(x), left(_left), right(_right) {}
};

int dfs(TreeNode* root, int cur) {
    if (root == nullptr) {
        return 0;
    }
    cur *= 10;
    cur += root->val;
    if (root->left == nullptr && root->right == nullptr) {
        return cur;
    }
    int ans = dfs(root->left, cur);
    ans += dfs(root->right, cur);
    return ans;
}

int sumNumbers(TreeNode* root) {
    return dfs(root, 0);
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        int result = sumNumbers(root);
        int correct_result = 25;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        // assert(result == correct_result);
    }
    {
        cout << "=====Example 2=====\n";
        TreeNode *root = new TreeNode(4);
        root->left = new TreeNode(9);
        root->left->left = new TreeNode(5);
        root->left->right = new TreeNode(1);
        root->right = new TreeNode(0);
        int result = sumNumbers(root);
        int correct_result = 1026;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        // assert(result == correct_result);
    }
    return 0;
}
