#include "bits/stdc++.h"
using namespace std;

string reverseWords(string s) {
    vector<string> tokens;
    int i = 0;
    int j = 0;
    while (j < s.size()) {
        while (i < s.size() && s[i] == ' ') i += 1;
        j = i;
        while (j < s.size() && s[j] != ' ') j += 1;
        if (j > i) {
            string token = s.substr(i, j - i);
            tokens.push_back(token);
        }
        i = j;
    }
    string ret;
    for (int i = tokens.size()-1; i > 0; --i) {
        ret += tokens[i] + " ";
    }
    if (!tokens.empty())
        ret += tokens[0];
    return ret;
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
