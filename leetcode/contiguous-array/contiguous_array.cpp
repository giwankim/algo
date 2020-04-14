#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> hm;
    hm[0] = -1;

    int cnt = 0, max_len = 0;
    for (int i = 0; i < nums.size(); ++i) {
        cnt += (nums[i] == 0) ? -1 : 1;
        if (hm.count(cnt)) {
            max_len = max(max_len, i - hm[cnt]);
        } else {
            hm[cnt] = i;
        }
    }
    return max_len;
}

int main(int argc, char const *argv[]) {
    /* code */
    vector<int> nums = {0,1};
    cout << findMaxLength(nums) << "\n";
    nums = {0, 1, 0};
    cout << findMaxLength(nums) << "\n";
    return 0;
}
