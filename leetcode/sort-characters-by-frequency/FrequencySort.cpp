#include "bits/stdc++.h"
using namespace std;

string frequencySort(string s) {
    unordered_map<char, int> m;
    for (char c : s) {
        m[c] += 1;
    }

    priority_queue<pair<int, char>> pq;
    for (auto &p : m) {
        pq.emplace(p.second, p.first);
    }

    string ans = "";
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        for (int i = 0; i < p.first; ++i) {
            ans += p.second;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    {
        cout << frequencySort("tree") << endl;
    }
    {
        cout << frequencySort("cccaaa") << endl;
    }
    {
        cout << frequencySort("Aabb") << endl;
    }
    return 0;
}
