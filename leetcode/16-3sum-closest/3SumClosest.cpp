#include "bits/stdc++.h"
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    if (nums.size() < 3) return 0;
    sort(nums.begin(), nums.end());
    int ret = 2e9;
    for (int i = 0; i+2 < nums.size(); ++i) {
        int j = i+1;
        int k = nums.size()-1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (abs(sum - target) < abs(ret - target)) {
                ret = sum;
            }
            if (sum == target) {
                return target;
            } else if (sum < target) {
                j += 1;
            } else if (sum > target) {
                k -= 1;
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        vector<int> nums{-1, 2, 1, -4};
        int target = 1;
        int result = threeSumClosest(nums, target);
        int correct_result = 2;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        // assert(nums == correct_result);
    }
    return 0;
}
