#include "bits/stdc++.h"
using namespace std;

bool same(vector<int> &a, vector<int> &b)
{
    if (a.size() != b.size())
    {
        return false;
    }
    for (int i = 0; i < (int)a.size(); ++i)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

vector<int> findAnagrams(string s, string p)
{
    vector<int> cnts(26), window(26);
    for (char c : p)
    {
        cnts[c - 'a'] += 1;
    }

    vector<int> indices;
    int window_size = 0;

    for (int i = 0; i < (int)s.size(); ++i)
    {
        int charidx = s[i] - 'a';
        window[charidx] += 1;
        window_size += 1;

        if (window_size == (int)p.size())
        {
            if (same(cnts, window))
            {
                indices.push_back(i-p.size()+1);
            }
            window[s[i - p.size() + 1] -'a'] -= 1;
            window_size -= 1;
        }
    }
    return indices;
}

int main(int argc, char const *argv[])
{
    {
        auto result = findAnagrams("cbaebabacd", "abc");
        for (int x : result) {
            cout << x << " ";
        }
        cout << endl;
    }
    {
        for (int x : findAnagrams("abab", "ab")) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
