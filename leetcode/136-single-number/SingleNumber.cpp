#include "bits/stdc++.h"
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int x : nums) {
        ans ^= x;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        vector<int> nums {2, 2, 1};
        int result = singleNumber(nums);
        int correct_result = 1;
        cout << "Expected:\n\t" << correct_result << "\n";
        cout << "Output:\n\t" << result << "\n";
    }
    {
        cout << "=====Example 2=====\n";
        vector<int> nums {4, 1, 2, 1, 2};
        int result = singleNumber(nums);
        int correct_result = 4;
        cout << "Expected:\n\t" << correct_result << "\n";
        cout << "Output:\n\t" << result << "\n";
    }
    return 0;
}
