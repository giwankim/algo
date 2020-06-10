#include "bits/stdc++.h"
using namespace std;

bool isSubsequence(string s, string t) {
    // Check whether s is a subsequence to t
    if (s.empty()) {
        return true;
    }
    int n = (int)s.size();
    int m = (int)t.size();
    int i = 0;
    int j = 0;
    while (j < m) {
        if (s[i] == t[j]) {
            i += 1;
            j += 1;
        } else {
            j += 1;
        }
        if (i == n) {
            return true;
        }
    }
    return false;
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
