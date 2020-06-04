#include "bits/stdc++.h"
using namespace std;

void reverseString(vector<char>& s) {
    int i = 0, j = (int)s.size() - 1;
    while (i < j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i += 1;
        j -= 1;
    }
}

int main(int argc, char const *argv[])
{
    {
        vector<char> s {'h','e','l','l','o'};
        reverseString(s);
        for (char c : s) {
            cout << c << " ";
        }
        cout << endl;
        // o l l e h
    }
    {
        vector<char> s {'h','a','n','n', 'a', 'h'};
        reverseString(s);
        for (char c : s) {
            cout << c << " ";
        }
        cout << endl;
        // h a n n a h
    }
    return 0;
}
