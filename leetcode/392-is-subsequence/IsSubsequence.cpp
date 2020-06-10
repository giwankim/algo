#include "bits/stdc++.h"
using namespace std;

bool isSubsequence(string s, string t) {
    // Check whether s is a subsequence to t
    size_t i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            i += 1;
        }
        j += 1;
    }
    return i == s.size();
}

/*
Follow up:
There are lots of incoming S, say S_1, S_2, ... , S_k where k >= 1B,
and you want to check one by one to see if T has its subsequence.
*/

bool isSubsequence(vector<string>& strs, string t) {
    
}


int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1======\n";
        bool result = isSubsequence("abc", "ahbgdc");
        bool correct_result = true;
        cout << boolalpha;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        cout << noboolalpha;
        assert(result == correct_result);
    }
    {
        cout << "=====Example 2======\n";
        bool result = isSubsequence("axc", "ahbgdc");
        bool correct_result = false;
        cout << boolalpha;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        cout << noboolalpha;
        assert(result == correct_result);
    }
    return 0;
}
