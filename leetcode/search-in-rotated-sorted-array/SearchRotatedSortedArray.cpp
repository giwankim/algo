#include <bits/stdc++.h>
using namespace std;

int get_pivot(const vector<int>& nums)
{
    int lo = 0, hi = (int)nums.size() - 1;
    while (lo < hi)
    {
        if (nums[lo] < nums[hi]) return lo;
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[hi]) lo = mid + 1;
        else                      hi = mid;
    }
    return lo;
}

int bin_search(int lo, int hi, const vector<int>& nums, int target)
{
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) lo = mid + 1;
        else                    hi = mid - 1;
    }
    return -1;
}

int search(vector<int>& nums, int target)
{
    if (nums.empty()) return -1;

    int pivot = get_pivot(nums);
    if (pivot == 0)
        return bin_search(0, nums.size()-1, nums, target);
    
    if (nums[pivot] == target) return pivot;
    if (nums[0] <= target)      return bin_search(0, pivot-1, nums, target);
    return bin_search(pivot+1, nums.size()-1, nums, target);
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << search(nums, 0) << "\n";
    cout << search(nums, 3) << "\n";
    nums = {1,3};
    cout << search(nums, 3) << "\n";
    nums = {3,1};
    cout << get_pivot(nums) << "\n";
    cout << search(nums, 3) << "\n";
    return 0;
}
