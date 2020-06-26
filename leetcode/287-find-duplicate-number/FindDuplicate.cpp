#include "bits/stdc++.h"
using namespace std;

int findDuplicate(vector<int>& nums) {
    int slow = 0;
    int fast = 0;
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        vector<int> nums{1, 3, 4, 2, 2};
        int result = findDuplicate(nums);
        int correct_result = 2;
        cout << "Expected:\n\t" << correct_result << "\n";
        cout << "Output:\n\t" << result << "\n";
        // assert(result == correct_result);
    }
    {
        cout << "=====Example 2=====\n";
        vector<int> nums{3, 1, 3, 4, 2};
        int result = findDuplicate(nums);
        int correct_result = 3;
        cout << "Expected:\n\t" << correct_result << "\n";
        cout << "Output:\n\t" << result << "\n";
        // assert(result == correct_result);
    } 
    return 0;
}
