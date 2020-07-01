#include "bits/stdc++.h"
using namespace std;

int BruteForce(int n) {
    int ans = 0;
    long long sum = 0;
    while (sum < n) {
        sum += (ans + 1);
        if (sum > n) break;
        ans += 1;
    }
    return ans;
}

int arrangeCoins(int n) {
    int ans = -1;
    int lo = 0, hi = n;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        long long sum = mid * (mid + 1) / 2;
        if (sum == n) {
            return mid;
        } else if (sum < n) {
            lo = mid + 1;
            ans = mid;
        } else if (sum > n) {
            hi = mid - 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        int n = 5;
        int result = arrangeCoins(n);
        int correct_result = 2;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
    }
    {
        cout << "=====Example 2=====\n";
        int n = 8;
        int result = arrangeCoins(n);
        int correct_result = 3;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
    }
    {
        cout << "=====Example 3=====\n";
        int n = 1;
        int result = arrangeCoins(n);
        int correct_result = 1;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
    }
    {
        cout << "=====Example 4=====\n";
        int n = 0;
        int result = arrangeCoins(n);
        int correct_result = 0;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
    }
    {
        cout << "=====Example 5=====\n";
        int n = 3;
        int result = arrangeCoins(n);
        int correct_result = 2;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
    }
    return 0;
}
