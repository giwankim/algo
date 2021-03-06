#include "bits/stdc++.h"
using namespace std;

double Recursive(double x, long long n) {
    if (n == 0) return 1.0;
    if (n < 0) return 1 / Recursive(x, -n);
    double ret = 1.0;
    if (n % 2 == 1) {
        ret *= x;
    }
    double half = Recursive(x, n / 2);
    ret *= half * half;
    return ret;
}

double myPow(double x, int n) {
    long long i = n;
    if (i < 0) {
        i = -i;
        x = 1 / x;
    }
    double ret = 1.0;
    double prod = x;
    while (i) {
        if (i % 2 == 1) {
            ret *= prod;
        }
        prod *= prod;
        i /= 2;
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        double x = 2.0;
        int n = 10;
        double result = myPow(x, n);
        double correct_result = 1024.0;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        // assert(result == correct_result);
    }
    {
        cout << "=====Example 2=====\n";
        double x = 2.1;
        int n = 3;
        double result = myPow(x, n);
        double correct_result = 9.261;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        // assert(result == correct_result);
    }
    {
        cout << "=====Example 3=====\n";
        double x = 2.0;
        int n = -2;
        double result = myPow(x, n);
        double correct_result = 0.25;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        // assert(result == correct_result);
    }
    return 0;
}