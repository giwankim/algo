#include "bits/stdc++.h"
using namespace std;

int findMaxLength(vector<int>& nums) {
    int ans = 0;
    int cnt = 0;
    unordered_map<int, int> m;
    m[0] = -1;
    for (int i = 0; i < (int)nums.size(); ++i) {
        cnt += nums[i] == 0 ? -1 : 1;
        if (m.count(cnt)) {
            ans = max(ans, i - m[cnt]);
        } else {
            m[cnt] = i;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    {
        vector<int> nums {0,1};
        cout << findMaxLength(nums) << endl;  // 2
    }
    {
        vector<int> nums {0,1,0};
        cout << findMaxLength(nums) << endl;  // 2
    }
    return 0;
}
