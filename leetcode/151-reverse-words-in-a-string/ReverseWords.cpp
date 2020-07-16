#include "bits/stdc++.h"
using namespace std;

string reverseWords(string s) {
    reverse(s.begin(), s.end());
    int write_idx = 0;
    int i = 0;
    int j = 0;
    while (j < s.size()) {
        if (write_idx != 0) {
            s[write_idx++] = ' ';
        }
        while (i < s.size() && s[i] == ' ') {
            i += 1;
        }
        j = i;
        while (j < s.size() && s[j] != ' ') {
            s[write_idx++] = s[j++];
        }
        reverse(s.begin() + write_idx - (j - i), s.begin() + write_idx);
        i = j;
    }
    s.erase(s.begin() + write_idx, s.end());
    while (!s.empty() && s.back() == ' ')
        s.pop_back();
    return s;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        string s = "the sky is blue";
        string correct_result = "blue is sky the";
        string result = reverseWords(s);
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        // assert(result == correct_result);
    }
    {
        cout << "=====Example 2=====\n";
        string s = "  hello world!  ";
        string correct_result = "world! hello";
        string result = reverseWords(s);
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        // assert(result == correct_result);
    }
    {
        cout << "=====Example 3=====\n";
        string s = "a good   example";
        string correct_result = "example good a";
        string result = reverseWords(s);
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        // assert(result == correct_result);
    }
    return 0;
}
