#include "bits/stdc++.h"
using namespace std;

bool checkInclusion(string s1, string s2) {
        // if (s1.size() > s2.size())
        //     return false;
        vector<int> cnts(26), window(26);
        for (char c : s1)
            cnts[c - 'a'] += 1;
        for (int i = 0; i + 1 < (int)s1.size(); ++i) {
            int charidx = s2[i] - 'a';
            window[charidx] += 1;
        }
        for (int i = s1.size() - 1; i < (int)s2.size(); ++i) {
            int charidx = s2[i] - 'a';
            window[charidx] += 1;
            bool flag = true;
            for (int j = 0; j < (int)cnts.size(); ++j) {
                if (cnts[j] != window[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return true;
            int prev_charidx = s2[i - s1.size() + 1] - 'a';
            window[prev_charidx] -= 1;
        }
        return false;
}

int main(int argc, char const *argv[])
{
    {
        cout << checkInclusion("ab", "eidbaooo") << endl;  // 1
    }
    {
        cout << checkInclusion("ab", "eidboaoo") << endl;  // 0
    }
    return 0;
}
