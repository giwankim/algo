#include "bits/stdc++.h"
using namespace std;

void _print(const vector<int> &nums)
{
    if (nums.empty())
    {
        cout << "\n";
        return;
    }
    for (int i = 0; i + 1 < (int)nums.size(); ++i)
    {
        cout << nums[i] << ", ";
    }
    cout << nums.back() << "\n";
}

vector<int> get(int i, vector<int>& nums, unordered_map<int, vector<int>>& cache) {
    if (i == (int)nums.size())
        return vector<int>();
    if (cache.find(i) != cache.end())
        return cache[i];
    vector<int> ans;
    for (int j = 0; j < i; ++j) {
        if (nums[i] % nums[j] == 0) {
            vector<int> tmp = get(j, nums, cache);
            if (ans.size() < tmp.size())
                ans = tmp;
        }
    }
    ans.push_back(nums[i]);
    cache[i] = ans;
    return ans;
}

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    unordered_map<int, vector<int>> cache;
    vector<int> ans;
    for (int i = 0; i < (int)nums.size(); ++i) {
        vector<int> tmp = get(i, nums, cache);
        if (ans.size() < tmp.size()) {
            ans = tmp;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    {
        cout << "=====Example 1=====\n";
        vector<int> nums{1, 2, 3};
        vector<int> result = largestDivisibleSubset(nums);
        vector<int> correct_result{1, 2};
        cout << "Expected:\n\t";
        _print(correct_result);
        cout << "Output:\n\t";
        _print(result);
        assert(result == correct_result);
    }
    {
        cout << "=====Example 2=====\n";
        vector<int> nums{1, 2, 4, 8};
        vector<int> result = largestDivisibleSubset(nums);
        vector<int> correct_result{1, 2, 4, 8};
        cout << "Expected:\n\t";
        _print(correct_result);
        cout << "Output:\n\t";
        _print(result);
        assert(result == correct_result);
    }
    return 0;
}
