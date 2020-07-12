#include "bits/stdc++.h"
using namespace std;

void backtrack(int i, vector<int>& nums, vector<int> set, vector<vector<int>>& sets) {
    if (i == nums.size()) {
        sets.push_back(set);
        return;
    }
    backtrack(i+1, nums, set, sets);
    set.push_back(nums[i]);
    backtrack(i+1, nums, set, sets);
    set.pop_back();
}

vector<vector<int>> recurse(vector<int>& nums) {
    vector<vector<int>> sets;
    vector<int> set;
    backtrack(0, nums, set, sets);
    return sets;
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ret;
    for (int i = 0; i < (1 << nums.size()); ++i) {
        vector<int> set;
        for (int j = 0; j < nums.size(); ++j) {
            if (i & (1 << j)) {
                set.push_back(nums[j]);
            }
        }
        ret.push_back(set);
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        vector<int> nums{1, 2, 3};
        vector<vector<int>> result = subsets(nums);
        for (int i = 0; i < result.size(); ++i) {
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
