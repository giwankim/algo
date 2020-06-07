#include "bits/stdc++.h"
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> s1(nums1.begin(), nums1.end());
    vector<int> ans;
    for (int x : nums2) {
        if (s1.count(x)) {
            ans.push_back(x);
            s1.erase(x);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    {
        vector<int> nums1 {1, 2, 2, 1};
        vector<int> nums2 {2,2};
        for (int x : intersection(nums1, nums2)) {
            cout << x << " ";
        }
        cout << endl;
        // 2
    }
    {
        vector<int> nums1 {4,9,5};
        vector<int> nums2 {9,4,9,8,4};
        for (int x : intersection(nums1, nums2)) {
            cout << x << " ";
        }
        cout << endl;
        // 9 4
    }
    return 0;
}
