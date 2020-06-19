#include "bits/stdc++.h"
using namespace std;

int hIndexLinear(vector<int> &citations)
{
    int n = (int)citations.size();
    for (int i = 0; i < (int)citations.size(); ++i)
    {
        if (n - i <= citations[i])
            return n - i;
    }
    return 0;
}

int hIndex(vector<int> &citations)
{
    int n = (int)citations.size();
    int lo = 0, hi = (int)citations.size() - 1;
    int ans = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        cout << lo << " " << mid << " " << hi << "\n";
        if (n - mid == citations[mid]) {
            return n - mid;
        } else if (n - mid < citations[mid]) {
            hi = mid - 1;
        } else if (n - mid >= citations[mid]) {
            ans = n - mid;
            lo = mid + 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    {
        cout << "=====Example 1=====\n";
        vector<int> citations{0, 1, 3, 5, 6};
        int result = hIndex(citations);
        int correct_result = 3;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        assert(result == correct_result);
    }
    {
        cout << "=====Example 2=====\n";
        vector<int> citations{2, 4, 6, 7, 8, 13, 14};
        int result = hIndex(citations);
        int correct_result = 5;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        assert(result == correct_result);
    }

    return 0;
}
