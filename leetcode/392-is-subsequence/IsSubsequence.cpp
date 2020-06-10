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
bool isSubsequence2(string s, string t) {
    unordered_map<char, vector<int>> char2indices;
    for (size_t i = 0; i < t.size(); ++i) {
        char2indices[t[i]].push_back(i);
    }
    int curr = -1;
    for (char c : s) {
        auto it = char2indices.find(c);
        if (it == char2indices.end()) {
            return false;
        }
        vector<int> &indices = it->second;
        auto idx_it = upper_bound(indices.begin(), indices.end(), curr);
        if (idx_it == indices.end()) {
            return false;
        }
        curr = *idx_it;
    }
    return true;
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
    {
        cout << "=====Example 1======\n";
        bool result = isSubsequence2("abc", "ahbgdc");
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
        bool result = isSubsequence2("axc", "ahbgdc");
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
