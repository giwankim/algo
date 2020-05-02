#include "bits/stdc++.h"
using namespace std;

int numJewelsInStones(string J, string S)
{
    int ans = 0;
    vector<int> cnts(128);
    for (char j : J) ++cnts[j];
    for (char s : S) {
        if (cnts[s] > 0) ++ans;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cout << numJewelsInStones("aA", "aAAbbbb") << endl;  // 3
    cout << numJewelsInStones("z", "ZZ") << endl;  // 0
    return 0;
}
