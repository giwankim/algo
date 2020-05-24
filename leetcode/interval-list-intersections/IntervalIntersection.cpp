#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> ans;
    int i = 0, j = 0;
    while (i < (int)A.size() && j < (int)B.size()) {
        if (A[i][1] < B[j][0]) {
            i += 1;
        } else if (B[j][1] < A[i][0]) {
            j += 1;
        } else {
            vector<int> v(2);
            v[0] = max(A[i][0], B[j][0]);
            v[1] = min(A[i][1], B[j][1]);
            ans.push_back(v);
            if (A[i][1] < B[j][1])
                i += 1;
            else
                j += 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    {
        vector<vector<int>> A {{0,2}, {5,10}, {13,23}, {24,25}};
        vector<vector<int>> B {{1,2}, {5,5}, {8,10}, {15,23}, {24,24}, {25,25}};
        vector<vector<int>> res = intervalIntersection(A, B);
        cout << "\n";
        for (auto& v : res) {
            for (int i = 0; i < (int)v.size(); i += 2) {
                cout << v[i] << ", " << v[i+1] << "\n";
            }
        }
    }
    return 0;
}
