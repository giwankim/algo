#include "bits/stdc++.h"
using namespace std;

int findComplement(int num)
{
    vector<int> bits;
    while (num) {
        bits.push_back(num & 1);
        num >>= 1;
    }
    int ans = 0;
    for (int i = 0; i < (int)bits.size(); ++i) {
        if (bits[i] == 0)
            ans |= 1 << i;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cout << findComplement(5) << endl;  // 2
    cout << findComplement(1) << endl;  // 0
    cout << findComplement(2) << endl;  // 1
    return 0;
}
