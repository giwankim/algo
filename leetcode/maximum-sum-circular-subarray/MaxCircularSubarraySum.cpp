#include "bits/stdc++.h"
using namespace std;
#define MAX 99999

int maxSubarraySumCircular(vector<int>& A) {
    int max_sum = A[0];
    int curr = 0;
    bool flag = false;
    for (int i = 0; i < A.size(); ++i) {
        curr = max(curr + A[i], A[i]);
        max_sum = max(max_sum, curr);
        if (A[i] > 0) {
            flag = true;
        }
    }

    if (!flag) {
        return max_sum;
    }

    int min_sum = A[0];
    int total = 0;
    curr = 0;
    for (int i = 0; i < A.size(); ++i) {
        curr = min(curr + A[i], A[i]);
        min_sum = min(min_sum, curr);
        total += A[i];
    }
    return max(max_sum, total - min_sum);
}

int main(int argc, char const *argv[])
{
    {
        vector<int> A {1,-2,3,-2};
        cout << maxSubarraySumCircular(A) << endl;  // 3
    }

    {
        vector<int> A {5,-3,5};
        cout << maxSubarraySumCircular(A) << endl;  // 10
    }

    {
        vector<int> A {3,-1,2,-1};
        cout << maxSubarraySumCircular(A) << endl;  // 4
    }

    {
        vector<int> A {3,-2,2,-3};
        cout << maxSubarraySumCircular(A) << endl;  // 3
    }

    {
        vector<int> A {-2,-3,-1};
        cout << maxSubarraySumCircular(A) << endl;  // -1
    }
    return 0;
}
