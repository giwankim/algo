#include "bits/stdc++.h"
using namespace std;

bool isPerfectSquare(int num)
{
    for (long long i = 1; i * i <= num; ++i)
    {
        if (i * i == num)
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    cout << isPerfectSquare(16) << endl; // true
    cout << isPerfectSquare(14) << endl; // false
    return 0;
}
