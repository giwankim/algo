#include "bits/stdc++.h"
using namespace std;

int firstUniqChar(string s) {
    vector<int> cnts(26);
    for (char c : s) {
        cnts[c - 'a'] += 1;
    }
    for (int i = 0; i < (int)s.size(); ++i) {
        if (cnts[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    cout << firstUniqChar("leetcode") << endl;     // 0
    cout << firstUniqChar("loveleetcode") << endl; // 2
    return 0;
}
