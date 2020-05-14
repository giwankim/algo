#include "bits/stdc++.h"
using namespace std;

string removeKdigits(string num, int k) {
    stack<char> s;
    for (char c : num) {
        while (!s.empty() && s.top() > c && k > 0) {
            s.pop();
            k -= 1;
        }
        s.push(c);
    }
    while (k-- > 0)
        s.pop();
    string result = "";
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }
    for (int i = (int)result.size() - 1; i >= 0 && result[i] == '0'; --i)
        result.pop_back();
    reverse(result.begin(), result.end());
    return result.empty() ? "0" : result;
}

int main(int argc, char const *argv[])
{
    {
        cout << removeKdigits("1432219", 3) << endl;  // "1219"
    }
    {
        cout << removeKdigits("10200", 1) << endl;  // "200"
    }
    {
        cout << removeKdigits("10", 2) << endl;  // "0"
    }
    {
        cout << removeKdigits("9", 1) << endl;  // "0"
    }
    return 0;
}
