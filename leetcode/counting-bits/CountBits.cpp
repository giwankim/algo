#include "bits/stdc++.h"
using namespace std;

vector<int> countBits(int num) {
    vector<int> T(num+1);
    T[0] = 0;
    for (int i = 1; i <= num; ++i) {
        if (i & 1)
            T[i] = T[i-1] + 1;
        else
            T[i] = T[i >> 1];
    }
    return T;
}

int main(int argc, char const *argv[])
{
    {
        for (int x : countBits(2)) {
            cout << x << ", ";  // 0,1,1
        }
        cout << endl;
    }
    {
        for (int x : countBits(5)) {
            cout << x << ", ";  // 0,1,1,2,1,2
        }
        cout << endl;
    }
    return 0;
}
