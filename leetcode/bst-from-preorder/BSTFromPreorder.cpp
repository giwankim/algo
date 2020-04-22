#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

pair<TreeNode*, int> bst(int i, int max_val, const vector<int>& preorder)
{
    if (i == preorder.size() || preorder[i] > max_val)
        return make_pair(nullptr, i);
    TreeNode *root = new TreeNode(preorder[i++]);
    tie(root->left, i) = bst(i, root->val, preorder);
    tie(root->right, i) = bst(i, max_val, preorder);
    return make_pair(root, i);
}

TreeNode* bstFromPreorder(vector<int>& preorder)
{
    return bst(0, INF, preorder).first;
}

int main(int argc, char const *argv[])
{
    vector<int> preorder = {8,5,1,7,10,12};
    TreeNode *root = bstFromPreorder(preorder);
    cout << root->val << "\n";
    cout << root->left->val << "\t" << root->right->val << "\n";
    cout << root->left->left->val<< "\t" << root->left->right->val << "\t" << root->right->right->val << "\n";
    return 0;
}
