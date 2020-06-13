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

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<int> prev(nums.size(), -1);
    vector<int> T(nums.size(), 1);
    int maxlen = 0, tail = -1;
    for (int i = 0; i < (int)nums.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] % nums[j] == 0)
            {
                int tmp = T[j] + 1;
                if (tmp > T[i])
                {
                    T[i] = tmp;
                    prev[i] = j;
                }
            }
        }
        if (T[i] > maxlen)
        {
            maxlen = T[i];
            tail = i;
        }
    }

    vector<int> ans;
    for (; tail != -1; tail = prev[tail])
    {
        ans.push_back(nums[tail]);
    }
    reverse(ans.begin(), ans.end());
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
        _print(result);
        cout << "Output:\n\t";
        _print(correct_result);
        assert(result == correct_result);
    }
    {
        cout << "=====Example 2=====\n";
        vector<int> nums{1, 2, 4, 8};
        vector<int> result = largestDivisibleSubset(nums);
        vector<int> correct_result{1, 2, 4, 8};
        cout << "Expected:\n\t";
        _print(result);
        cout << "Output:\n\t";
        _print(correct_result);
        assert(result == correct_result);
    }
    return 0;
}
