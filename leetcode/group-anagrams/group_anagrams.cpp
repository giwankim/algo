#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> grams;
    unordered_map<string, vector<string>> hmap;
    for (auto& s : strs)
    {
        auto t = s;
        sort(t.begin(), t.end());
        hmap[t].push_back(s);
    }
    for (auto& p : hmap)
    {
        grams.push_back(p.second);
    }
    return grams;
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto grams = groupAnagrams(strs);
    for (auto v : grams)
    {
        for (auto s : v)
        {
            cout << s << ",";
        }
        cout << '\n';
    }
    return 0;
}
