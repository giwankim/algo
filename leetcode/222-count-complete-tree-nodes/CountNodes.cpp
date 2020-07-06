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

int BruteForce(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + BruteForce(root->left) + BruteForce(root->right);
}

int Height(TreeNode* root) {
    int h = -1;
    TreeNode *cur = root;
    while (cur) {
        cur = cur->left;
        h += 1;
    }
    return h;
}

int countNodes(TreeNode* root) {
    int h = Height(root);
    if (h == -1) return 0;
    int h_right = Height(root->right);
    if (h_right == h-1) {
        return (1 << h) + countNodes(root->right);
    }
    return (1 << (h-1)) + countNodes(root->left);
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->right->left = new TreeNode(6);
        int result = countNodes(root);
        int correct_result = 6;
        cout << "Expected:\n\t" << correct_result << "\n";
        cout << "Output:\n\t" << result << "\n";
    }
    return 0;
}
