#include "bits/stdc++.h"
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int lo = 0, hi = (int)nums.size()-1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        // cout << lo << " " << mid << " " << hi << "\n";
        if ((mid & 1) == 1)
            --mid;
        if (nums[mid] == nums[mid+1])
            lo = mid + 2;
        else
            hi = mid;
    }
    return nums[lo];
}

int main() {
    {
        vector<int> nums = {1,1,2,3,3,4,4,8,8};
        cout << singleNonDuplicate(nums) << endl;
    }
}