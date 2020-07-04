#include "bits/stdc++.h"
using namespace std;

int nthUglyNumber(int n) {
    long long ret = -1;
    unordered_set<long long> seen;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    pq.push(1);
    for (int i = 0; i < n; ++i) {
        while (seen.find(pq.top()) != seen.end()) {
            pq.pop();
        }
        ret = pq.top();
        pq.pop();
        seen.insert(ret);
        pq.push(2 * ret);
        pq.push(3 * ret);
        pq.push(5 * ret);
    }
    return (int)ret;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        int n = 10;
        int result = nthUglyNumber(n);
        int correct_result = 12;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
    }
    return 0;
}