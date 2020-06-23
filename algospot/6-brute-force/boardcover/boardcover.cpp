#include "bits/stdc++.h"
using namespace std;

const int coverType[4][3][2] = {
    {{0, 0}, {1, 0}, {0, 1}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}},
};

int h, w;
vector<vector<int>> board;

void _print() {
    for (int i = 0; i < (int)board.size(); ++i) {
        for (int j = 0; j < (int)board[i].size(); ++j) {
            cerr << board[i][j] << " ";
        }
        cerr << "\n";
    }
    cerr << "\n";
}

bool Set(int y, int x, int type, int delta) {
    bool ok = true;
    for (int i = 0; i < 3; ++i) {
        int ny = y + coverType[type][i][0];
        int nx = x + coverType[type][i][1];
        if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
            ok = false;
        } else if ((board[ny][nx] += delta) > 1) {
            ok = false;
        }
    }
    return ok;
}

int Count() {
    int y = -1;
    int x = -1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (board[i][j] == 0) {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1)
            break;
    }
    if (y == -1 && x == -1)
        return 1;
    int ans = 0;
    for (int type = 0; type < 4; ++type) {
        if (Set(y, x, type, 1)) {
            ans += Count();
        }
        Set(y, x, type, -1);
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    // #ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // freopen("log.txt", "w", stderr);
    // #endif
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> h >> w;
        board.assign(h, vector<int>(w));
        int whites = 0;
        for (int i = 0; i < h; ++i) {
            string row;
            cin >> row;
            for (int j = 0; j < w; ++j) {
                board[i][j] = (row[j] == '#') ? 1 : 0;
            }
            whites += count(board[i].begin(), board[i].end(), 0);
        }

        if (whites % 3 != 0) {
            cout << 0 << "\n";
        } else {
            cout << Count() << "\n";
        }
    }
    return 0;
}
