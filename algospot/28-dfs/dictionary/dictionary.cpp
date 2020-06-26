#include "bits/stdc++.h"
using namespace std;
#define DEBUG 0

const int VISITED = 1, UNVISITED = -1, VISITING = 0, R = 26;

int n;
vector<vector<int>> adj;
vector<int> order;
vector<int> dfs_num;

// Adjacency matrix
void make_graph(const vector<string>& words) {
    adj.assign(R, vector<int>());
    for (int i = 0; i+1 < words.size(); ++i) {
        int j = i + 1;
        int len = min(words[i].size(), words[j].size());
        for (int k = 0; k < len; ++k) {
            if (words[i][k] == words[j][k])
                continue;
            int a = words[i][k] - 'a';
            int b = words[j][k] - 'a';
            adj[a].push_back(b);
            break;
        }
    }
}

bool dfs(int u) {
    if (DEBUG) {
        cerr << "Visiting " << char(u + 'a') << "\n";
    }

    dfs_num[u] = VISITING;

    for (int j = 0; j < adj[u].size(); ++j) {
        int v = adj[u][j];
        if (dfs_num[v] == VISITING) {
            return false;
        }
        if (dfs_num[v] == UNVISITED) {
            if (dfs(v) == false) {
                return false;
            }
        }
    }

    dfs_num[u] = VISITED;
    order.push_back(u);

    return true;
}

vector<int> topo_sort() {
    dfs_num.assign(adj.size(), UNVISITED);
    order.clear();

    for (int i = 0; i < adj.size(); ++i) {
        if (dfs_num[i] == UNVISITED) {
            if (dfs(i) == false) {
                return vector<int>();
            }
        }
    }

    reverse(order.begin(), order.end());

    return order;
}

int main(int argc, char const *argv[]) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> n;
        vector<string> words(n);
        for (int i = 0; i < n; ++i) {
            cin >> words[i];
        }

        make_graph(words);

        if (DEBUG) {
            for (int i = 0; i < adj.size(); ++i) {
                cerr << char(i + 'a') << ": ";
                for (int j = 0; j < adj[i].size(); ++j) {
                    cerr << char(adj[i][j] + 'a') << " ";
                }
                cerr << "\n";
            }
        }

        vector<int> topo = topo_sort();

        if (topo.empty()) {
            cout << "INVALID HYPOTHESIS\n";
        } else {
            for (int i = 0; i < topo.size(); ++i) {
                cout << char(topo[i] + 'a');
            }
            cout << "\n";
        }
    }

    return 0;
}