#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](const auto& lhs, const auto& rhs) {
        return lhs[0] == rhs[0] ? lhs[1] > rhs[1] : lhs[0] < rhs[0];
    });
    vector<vector<int>> ans(people.size(), vector<int>(2, -1));
    for (auto& p : people) {
        int cnt = p[1];
        for (auto& q : ans) {
            if (q[0] == -1) {
                if (cnt == 0) {
                    q = p;
                    break;
                } else {
                    cnt -= 1;
                }
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    {
        vector<vector<int>> people {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
        vector<vector<int>> queue = reconstructQueue(people);
        for (auto& p : queue) {
            cout << "(" << p[0] << "," << p[1] << ") ";
        }
        cout << endl;
        // (5,0) (7,0) (5,2) (6,1) (4,4) (7,1)
    }

    {
        vector<vector<int>> people {
            {2,4}, {3,4}, {9,0}, {0,6}, {7,1},
            {6,0}, {7,3},{2,5},{1,1},{8,0}
        };
        vector<vector<int>> queue = reconstructQueue(people);
        for (auto& p : queue) {
            cout << "(" << p[0] << "," << p[1] << ") ";
        }
        cout << endl;
        // {{6,0}, {1,1}, {8,0}, {7,1}, {9,0}, {2,4}, {0,6}, {2,5}, {3,4}, {7,3}}
    }
    return 0;
}
