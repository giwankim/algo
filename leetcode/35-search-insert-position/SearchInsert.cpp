#include "bits/stdc++.h"
using namespace std;

int searchInsertSTL(vector<int> &nums, int target)
{
    return distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
}

int searchInsert(vector<int> &nums, int target)
{
    int lo = 0;
    int hi = (int)nums.size() - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return lo;
}

int main()
{
    {
        cout << "=====Example 1=====\n";
        vector<int> nums{1, 3, 5, 6};
        int target = 5;
        int result = searchInsert(nums, target);
        int correct_result = 2;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        assert(result == correct_result);
    }
    {
        cout << "=====Example 2=====\n";
        vector<int> nums{1, 3, 5, 6};
        int target = 2;
        int result = searchInsert(nums, target);
        int correct_result = 1;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        assert(result == correct_result);
    }
    {
        cout << "=====Example 3=====\n";
        vector<int> nums{1, 3, 5, 6};
        int target = 7;
        int result = searchInsert(nums, target);
        int correct_result = 4;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        assert(result == correct_result);
    }
    {
        cout << "=====Example 4=====\n";
        vector<int> nums{1, 3, 5, 6};
        int target = 0;
        int result = searchInsert(nums, target);
        int correct_result = 0;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        assert(result == correct_result);
    }
    return 0;
}
