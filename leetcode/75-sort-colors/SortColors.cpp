#include "bits/stdc++.h"
using namespace std;

void _print(const vector<int> &nums)
{
    if (nums.empty())
        return;
    for (int i = 0; i + 1 < (int)nums.size(); ++i)
    {
        cout << nums[i] << ", ";
    }
    cout << nums.back() << endl;
}

void sortColors(vector<int> &nums)
{
    int n = (int)nums.size();
    int lt = 0;
    int gt = n - 1;
    int val = 1;
    for (int i = 0; i <= gt;) {
        if (nums[i] < val) {
            swap(nums[i++], nums[lt++]);
        } else if (nums[i] > val) {
            swap(nums[i], nums[gt--]);
        } else {
            i += 1;
        }
    }
}

int main(int argc, char const *argv[])
{
    {
        cout << "===== Example 1 =====\n";
        vector<int> nums{2, 0, 2, 1, 1, 0};
        sortColors(nums);
        vector<int> correct_result{0, 0, 1, 1, 2, 2};
        cout << "Expected:\n\t";
        _print(correct_result);
        cout << "Output:\n\t";
        _print(nums);
        assert(nums == correct_result);
    }
    {
        cout << "===== Example 2 =====\n";
        vector<int> nums{2, 0, 1};
        sortColors(nums);
        vector<int> correct_result{0, 1, 2};
        cout << "Expected:\n\t";
        _print(correct_result);
        cout << "Output:\n\t";
        _print(nums);
        assert(nums == correct_result);
    }
    return 0;
}
