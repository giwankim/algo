#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    sort(points.begin(), points.end(), [](auto& p1, auto& p2) {
        return p1[0]*p1[0] + p1[1]*p1[1] < p2[0]*p2[0] + p2[1]*p2[1];
    });
    return vector<vector<int>>(points.begin(), points.begin()+K);
}

int main(int argc, char const *argv[])
{
    {
        vector<vector<int>> points {{1,3}, {-2,2}};
        int K = 1;
        for (auto& p : kClosest(points, K)) {
            cout << "(" << p[0] << ", " << p[1] << "), ";
        }
        cout << "\n";
        // (-2, 2)
    }
    {
        vector<vector<int>> points {{3,3}, {5,-1}, {-2,4}};
        int K = 2;
        for (auto& p : kClosest(points, K)) {
            cout << "(" << p[0] << ", " << p[1] << "), ";
        }
        cout << "\n";
        // (3, 3), (-2, 4)
    }
    return 0;
}
