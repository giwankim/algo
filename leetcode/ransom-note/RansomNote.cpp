#include "bits/stdc++.h"
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    vector<int> cnts(128);
    for (char c : magazine)
        ++cnts[c];
    for (char c : ransomNote) {
        if (--cnts[c] < 0)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    cout << canConstruct("aa", "aab") << endl;
    return 0;
}
