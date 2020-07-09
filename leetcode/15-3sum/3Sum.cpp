#include "bits/stdc++.h"
using namespace std;

void _print(const vector<vector<int>>& vecs) {
    for (const auto& vec : vecs) {
        for (int x : vec) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) return vector<vector<int>>();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    for (int i = 0; i+2 < nums.size(); ++i) {
        if (i > 0 && nums[i-1] == nums[i]) continue;
        int j = i+1;
        int k = nums.size()-1;
        while (j < k) {
            long long sum = nums[i] + nums[j] + nums[k];
            if (sum < 0) {
                j += 1;
            } else if (sum > 0) {
                k -= 1;
            } else {
                ret.push_back({nums[i], nums[j], nums[k]});
                while (j < k && nums[j] == nums[j+1]) j += 1;
                while (j < k && nums[k-1] == nums[k]) k -= 1;
                j += 1;
                k -= 1;
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        vector<int> nums{-1, 0, 1, 2, -1, -4};
        vector<vector<int>> result = threeSum(nums);
        vector<vector<int>> correct_result{{-1, 0, 1}, {-1, -1, 2}};
        cout << "Expected:\n";
        _print(correct_result);
        cout << "Output:\n";
        _print(result);
        // assert(nums == correct_result);
    }
    return 0;
}
