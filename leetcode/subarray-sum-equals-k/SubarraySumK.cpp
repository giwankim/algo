#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> cache;
    cache[0] = 1;
    int ans = 0, sum = 0;
    for (int x : nums)
    {
        sum += x;
        if (cache.count(sum-k)) ans += cache[sum-k];
        cache[sum] += 1;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> nums {1,1,1};
    cout << subarraySum(nums, 2) << "\n";  // 2
    return 0;
}
