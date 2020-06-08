#include "bits/stdc++.h"
using namespace std;

bool isPowerOfTwo(int n) {
    if (n == 0)
        return false;
    long long m = n;
    if (m < 0)
        m = n;
    return (m & (m - 1)) == 0;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        int n = 1;
        bool result = isPowerOfTwo(n);
        bool correct_result = true;
        cout << "Expected:\n\t";
        cout << boolalpha;
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        cout << noboolalpha;
        assert(result == correct_result);
    }
    {
        cout << "=====Example 2=====\n";
        int n = 16;
        bool result = isPowerOfTwo(n);
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
        cout << "=====Example 3=====\n";
        int n = 218;
        bool result = isPowerOfTwo(n);
        bool correct_result = false;
        cout << boolalpha;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        cout << noboolalpha;
        assert(result == correct_result);
    }
    {
        cout << "=====Example 4=====\n";
        int n = -2147483648;
        bool result = isPowerOfTwo(n);
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
