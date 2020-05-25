#include "bits/stdc++.h"
using namespace std;

int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    vector<vector<int>> T(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            T[i][j] = max(T[i-1][j], T[i][j-1]);
            if (A[i-1] == B[j-1]) {
                T[i][j] = max(T[i][j], 1 + T[i-1][j-1]);
            }
        }
    }
    return T[n][m];
}

int main(int argc, char const *argv[])
{
    {
        vector<int> A {1,4,2};
        vector<int> B {1,2,4};
        cout << maxUncrossedLines(A, B) << endl;  // 2
    }
    {
        vector<int> A {2,5,1,2,5};
        vector<int> B {10,5,2,1,5,2};
        cout << maxUncrossedLines(A, B) << endl;  // 3
    }
    {
        vector<int> A {1,3,7,1,7,5};
        vector<int> B {1,9,2,5,1};
        cout << maxUncrossedLines(A, B) << endl;  // 2
    }
    return 0;
}
