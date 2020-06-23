#include "bits/stdc++.h"
using namespace std;

int singleNumber(vector<int>& nums) {
    int once = 0;
    int twice = 0;
    for (int x: nums) {
        once = (once ^ x) & ~twice;
        twice = (twice ^ x) & ~once;
        // cout << "x: " << x << ", ";
        // cout << "once: " << once << ", ";
        // cout << "twice: "<< twice << "\n";
    }
    return once;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        vector<int> nums {2, 2, 3, 2};
        int result = singleNumber(nums);
        int correct_result = 3;
        cout << "Expected:\n\t" << correct_result << "\n";
        cout << "Output:\n\t" << result << "\n";
        assert(result == correct_result);
    }
    {
        cout << "=====Example 2=====\n";
        vector<int> nums {0, 1, 0, 1, 0, 1, 99};
        int result = singleNumber(nums);
        int correct_result = 99;
        cout << "Expected:\n\t" << correct_result << "\n";
        cout << "Output:\n\t" << result << "\n";
        assert(result == correct_result);
    }
    return 0;
}
