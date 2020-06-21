#include "bits/stdc++.h"
using namespace std;

void _print(vector<int> &nums) {
    for (int x : nums) {
        cout << x << " ";
    }
    cout << "\n";
}

void nextPermutation(vector<int> &nums) {
    int i;
    for (i = (int)nums.size() - 2; i >= 0 && nums[i] >= nums[i+1]; --i);
    if (i < 0) {
        reverse(nums.begin(), nums.end());
        return;
    }
    int j;
    for (j = (int)nums.size() - 1; j > i && nums[i] >= nums[j]; --j);
    swap(nums[i], nums[j]);
    reverse(nums.begin() + i + 1, nums.end());
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        vector<int> nums{1, 2, 3};
        nextPermutation(nums);
        vector<int> correct_result{1, 3, 2};
        cout << "Expected:\n\t";
        _print(correct_result);
        cout << "Output:\n\t";
        _print(nums);
        assert(nums == correct_result);
    }
    {
        cout << "=====Example 2=====\n";
        vector<int> nums{3, 2, 1};
        nextPermutation(nums);
        vector<int> correct_result{1, 2, 3};
        cout << "Expected:\n\t";
        _print(correct_result);
        cout << "Output:\n\t";
        _print(nums);
        assert(nums == correct_result);
    }
    {
        cout << "=====Example 3=====\n";
        vector<int> nums{1, 1, 5};
        nextPermutation(nums);
        vector<int> correct_result{1, 5, 1};
        cout << "Expected:\n\t";
        _print(correct_result);
        cout << "Output:\n\t";
        _print(nums);
        assert(nums == correct_result);
    }
    {
        cout << "=====Example 4=====\n";
        vector<int> nums{1, 1};
        nextPermutation(nums);
        vector<int> correct_result{1, 1};
        cout << "Expected:\n\t";
        _print(correct_result);
        cout << "Output:\n\t";
        _print(nums);
        assert(nums == correct_result);
    }
    {
        cout << "=====Example 5=====\n";
        vector<int> nums{1, 3, 2};
        nextPermutation(nums);
        vector<int> correct_result{2, 1, 3};
        cout << "Expected:\n\t";
        _print(correct_result);
        cout << "Output:\n\t";
        _print(nums);
        assert(nums == correct_result);
    }
    {
        cout << "=====Example 6=====\n";
        vector<int> nums{5, 1, 1};
        nextPermutation(nums);
        vector<int> correct_result{1, 1, 5};
        cout << "Expected:\n\t";
        _print(correct_result);
        cout << "Output:\n\t";
        _print(nums);
        assert(nums == correct_result);
    }
    return 0;
}
