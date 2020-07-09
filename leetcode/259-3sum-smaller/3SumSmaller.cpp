#include "bits/stdc++.h"
using namespace std;

int threeSumSmaller(vector<int>& nums, int target) {
    if (nums.size() < 3) return 0;
    sort(nums.begin(), nums.end());
    int ret = 0;
    for (int i = 0; i+2 < nums.size(); ++i) {
        int j = i+1;
        int k = nums.size()-1;
        while (j < k) {
            if (nums[i] + nums[j] + nums[k] < target) {
                ret += k - j;
                j += 1;
            } else {
                k -= 1;
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        vector<int> nums{-2, 0, 1, 3};
        int target = 2;
        int result = threeSumSmaller(nums, target);
        int correct_result = 2;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        // assert(nums == correct_result);
    }
    return 0;
}
