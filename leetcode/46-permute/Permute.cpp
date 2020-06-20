#include "bits/stdc++.h"
using namespace std;

void _print(vector<vector<int>>& vecs) {
    for (int i = 0; i < (int)vecs.size(); ++i) {
        for (int j = 0; j < (int)vecs[i].size(); ++j) {
            cout << vecs[i][j] << " ";
        }
        cout << "\n";
    }
}

void backtrack(int i, vector<int>& nums, vector<vector<int>>& ans) {
    if (i == (int)nums.size()) {
        ans.push_back(nums);
        return;
    }
    for (int j = i; j < (int)nums.size(); ++j) {
        swap(nums[i], nums[j]);
        backtrack(i + 1, nums, ans);
        swap(nums[i], nums[j]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    backtrack(0, nums, ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    {
        cout << "=====Example 1=====\n";
        vector<int> nums{1, 2, 3};
        vector<vector<int>> result = permute(nums);
        vector<vector<int>> correct_result = {
            {1,2,3}, {1,3,2}, {2,1,3},
            {2,3,1}, {3,1,2}, {3,2,1},
        };
        sort(result.begin(), result.end());
        sort(correct_result.begin(), correct_result.end());
        cout << "Expected:\n";
        _print(correct_result);
        cout << "Output:\n";
        _print(result);
        assert(result == correct_result);
    }
    return 0;
}
