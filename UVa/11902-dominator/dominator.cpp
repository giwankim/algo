#include "bits/stdc++.h"
using namespace std;

enum { UNVISITED, VISITED };

int n;
vector<vector<int>> adj;
vector<int> dfs_num, dfs_num2;


void make_graph() {
    dfs_num.assign(n, UNVISITED);
    dfs_num2.assign(n, UNVISITED);
    adj.assign(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            if (x) adj[i].push_back(j);
        }
    }
}

void dfs(int u) {
    dfs_num[u] = VISITED;
    for (int j = 0; j < adj[u].size(); ++j) {
        int v = adj[u][j];
        if (dfs_num[v] == UNVISITED) {
            dfs(v);
        }
    }
}

void dfs2(int u, int x) {
    if (u == x) return;
    dfs_num2[u] = VISITED;
    for (int j = 0; j < adj[u].size(); ++j) {
        int v = adj[u][j];
        if (dfs_num2[v] == UNVISITED) {
            dfs2(v, x);
        }
    }
}

vector<vector<bool>> dominator() {
    vector<vector<bool>> ret(n, vector<bool>(n, false));
    make_graph();
    dfs(0);
    for (int i = 0; i < n; ++i) {
        dfs_num2.assign(n, UNVISITED);
        dfs2(0, i);
        for (int j = 0; j < n; ++j) {
            if (dfs_num[j] == VISITED && dfs_num2[j] == UNVISITED) {
                ret[i][j] = true;
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
    #endif
    int cases;
    cin >> cases;
    for (int cc = 1; cc <= cases; ++cc) {
        cin >> n;
        vector<vector<bool>> dominates = dominator();
        cout << "Case " << cc << ":\n";
        string border = "+" + string(2*n-1, '-') + "+";
        cout << border << "\n";
        for (int i = 0; i < n; ++i) {
            cout << "|";
            for (int j = 0; j < n; ++j) {
                cout << (dominates[i][j] ? "Y" : "N") << "|";
            }
            cout << "\n";
            cout << border << "\n";
        }
    }
    return 0;
}
