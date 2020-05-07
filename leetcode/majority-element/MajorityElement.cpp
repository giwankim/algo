#include "bits/stdc++.h"
using namespace std;

int majorityElement(vector<int>& nums) {
    int ans = -1, cnt = 0;
    for (int x : nums) {
        if (cnt == 0) {
            ans = x;
            cnt = 1;
        } else if (ans == x) {
            cnt += 1;
        } else {
            --cnt;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    {
        vector<int> nums = {3, 2, 3};
        cout << majorityElement(nums) << endl;  // 3
    }
    {
        vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
        cout << majorityElement(nums) << endl;  // 2
    }

    
    return 0;
}
