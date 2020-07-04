#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* _left, TreeNode* _right) : val(x), left(_left), right(_right) {}
};

void _print(vector<vector<int>>& vecs) {
    for (int i = 0; i < vecs.size(); ++i) {
        for (int j = 0; j < vecs[i].size(); ++j) {
            cout << vecs[i][j] << " ";
        }
        cout << "\n";
    }
}

void dfs(int i, TreeNode *root, vector<vector<int>>& levels) {
    if (root == nullptr) return;
    if (levels.size() < i+1) {
        levels.push_back({});
    }
    levels[i].push_back(root->val);
    dfs(i+1, root->left, levels);
    dfs(i+1, root->right, levels);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ret;
    dfs(0, root, ret);
    reverse(ret.begin(), ret.end());
    return ret;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);
        vector<vector<int>> result = levelOrderBottom(root);
        vector<vector<int>> correct_result{{15, 7}, {9, 20}, {3}};
        cout << "Expected:\n";
        _print(correct_result);
        cout << "Output:\n";
        _print(result);
    }
    return 0;
}
