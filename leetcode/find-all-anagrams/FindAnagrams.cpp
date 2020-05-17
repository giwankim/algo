#include "bits/stdc++.h"
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    int n = s.size(), m = p.size();
    if (n < m)
    {
        return vector<int>();
    }
    vector<int> cnts(26), window(26);
    for (char c : p)
    {
        cnts[c - 'a'] += 1;
    }
    for (int i = 0; i < m - 1; ++i)
    {
        window[s[i] - 'a'] += 1;
    }
    vector<int> indices;
    for (int i = m - 1; i < n; ++i)
    {
        window[s[i] - 'a'] += 1;
        bool flag = true;
        for (int j = 0; j < (int)cnts.size(); ++j)
        {
            if (cnts[j] != window[j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            indices.push_back(i - m + 1);
        }
        window[s[i - m + 1] - 'a'] -= 1;
    }
    return indices;
}

int main(int argc, char const *argv[])
{
    {
        auto result = findAnagrams("cbaebabacd", "abc");
        for (int x : result)
        {
            cout << x << " "; // 0 6
        }
        cout << endl;
    }

    {
        for (int x : findAnagrams("abab", "ab"))
        {
            cout << x << " "; // 0 1 2
        }
        cout << endl;
    }

    {
        for (int x : findAnagrams("aaaaaaaaaa", "aaaaaaaaaaaaa"))
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
