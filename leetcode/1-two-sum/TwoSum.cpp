#include "bits/stdc++.h"
using namespace std;

void _print(vector<int>& v) {
    for (int x : v)
        cout << x << " ";
    cout << "\n";
}

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ret;
    unordered_map<int, int> memo;
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (memo.find(complement) != memo.end()) {
            ret.push_back(memo[complement]);
            ret.push_back(i);
            break;
        }
        memo[nums[i]] = i;
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        vector<int> nums{2, 7, 11, 15};
        int target = 9;
        vector<int> result = twoSum(nums, target);
        vector<int> correct_result{0, 1};
        cout << "Expected:\n";
        _print(correct_result);
        cout << "Output:\n";
        _print(result);
        // assert(nums == correct_result);
    }
    return 0;
}
