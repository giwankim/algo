#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left_, TreeNode *right_) : val(x), left(left_), right(right_) {}
};

bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr || q == nullptr)
        return p == q;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(int argc, char const *argv[]) {
    cout << boolalpha;
    {
        cout << "======Example 1=====\n";
        TreeNode *p = new TreeNode(1);
        p->left = new TreeNode(2);
        p->right = new TreeNode(3);
        TreeNode *q = new TreeNode(1);
        q->left = new TreeNode(2);
        q->right = new TreeNode(3);
        bool result = isSameTree(p, q);
        bool correct_result = true;
        cout << "Expected:\n\t";
        cout << result << "\n";
        cout << "Output:\n\t";
        cout << correct_result << "\n";
    }
    {
        cout << "======Example 2=====\n";
        TreeNode *p = new TreeNode(1);
        p->left = new TreeNode(2);
        TreeNode *q = new TreeNode(1);
        q->right = new TreeNode(2);
        bool result = isSameTree(p, q);
        bool correct_result = false;
        cout << "Expected:\n\t";
        cout << result << "\n";
        cout << "Output:\n\t";
        cout << correct_result << "\n";
    }
    {
        cout << "======Example 3=====\n";
        TreeNode *p = new TreeNode(1);
        p->left = new TreeNode(2);
        p->right = new TreeNode(1);
        TreeNode *q = new TreeNode(1);
        q->left = new TreeNode(1);
        q->right = new TreeNode(2);
        bool result = isSameTree(p, q);
        bool correct_result = false;
        cout << "Expected:\n\t";
        cout << result << "\n";
        cout << "Output:\n\t";
        cout << correct_result << "\n";
    }
    cout << noboolalpha;
    return 0;
}
