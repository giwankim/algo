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
