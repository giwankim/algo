#include "bits/stdc++.h"
using namespace std;

void _print(const vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    vector<int> ret(digits);
    int carry = 1;
    for (int i = n-1; i >= 0; --i) {
        ret[i] += carry;
        carry = ret[i] / 10;
        ret[i] %= 10;
    }
    if (carry) {
        ret.insert(ret.begin(), carry);
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        vector<int> digits{1, 2, 3};
        vector<int> result = plusOne(digits);
        vector<int> correct_result{1, 2, 4};
        cout << "Expected:\n\t";
        _print(correct_result);
        cout << "Output:\n\t";
        _print(result);
        // assert(result == correct_result);
    }
    {
        cout << "=====Example 2=====\n";
        vector<int> digits{4, 3, 2, 1};
        vector<int> result = plusOne(digits);
        vector<int> correct_result{4, 3, 2, 2};
        cout << "Expected:\n\t";
        _print(correct_result);
        cout << "Output:\n\t";
        _print(result);
        // assert(result == correct_result);
    }
    return 0;
}
