#include "bits/stdc++.h"
using namespace std;

void _print(vector<int>& nums) {
    for (int x : nums) {
        cout << x << " ";
    }
    cout << "\n";
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (int x : nums) {
        mp[x] += 1;
    }
    priority_queue<pair<int, int>> pq;
    for (auto& p : mp) {
        pq.emplace(p.second, p.first);
    }
    vector<int> ret(k);
    for (int i = 0; i < k; ++i) {
        auto p = pq.top();
        pq.pop();
        ret[i] = p.second;
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        vector<int> nums{1, 1, 1, 2, 2, 3};
        int k = 2;
        vector<int> result = topKFrequent(nums, k);
        vector<int> correct_result{1, 2};
        cout << "Expected:\n";
        _print(correct_result);
        cout << "Output:\n";
        _print(result);
    }

    {
        cout << "=====Example 2=====\n";
        vector<int> nums{1};
        int k = 1;
        vector<int> result = topKFrequent(nums, k);
        vector<int> correct_result{1};
        cout << "Expected:\n";
        _print(correct_result);
        cout << "Output:\n";
        _print(result);
    }
    return 0;
}
