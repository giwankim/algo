#include "bits/stdc++.h"
using namespace std;

const int INF = 1e9;
const int SWITCH = 10, CLOCKS = 16;

const vector<int> switches[SWITCH] = {
    {0, 1, 2},
    {3, 7, 9, 11},
    {4, 10, 14, 15},
    {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12},
    {0, 2, 14, 15},
    {3, 14, 15},
    {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5},
    {3, 4, 5, 9, 13},
};
vector<int> clocks(CLOCKS);

void push(int i) {
    for (int j = 0; j < (int)switches[i].size(); ++j) {
        int clock = switches[i][j];
        clocks[clock] += 3;
        if (clocks[clock] == 15)
            clocks[clock] = 3;
    }
}

int solve(int i) {
    if (i == SWITCH) {
        bool ok = true;
        for (int j = 0; j < CLOCKS; ++j) {
            if (clocks[j] != 12) {
                ok = false;
                break;
            }
        }
        return ok ? 0 : INF;
    }
    int ans = INF;
    for (int cnt = 0; cnt < 4; ++cnt) {
        ans = min(ans, cnt + solve(i + 1));
        push(i);
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
    int cases;
    cin >> cases;
    while (cases--) {
        for (int& clock : clocks) {
            cin >> clock;
        }
        int ans = solve(0);
        cout << (ans == INF ? -1 : ans) << "\n";
    }
    return 0;
}
