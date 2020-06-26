#include "bits/stdc++.h"
using namespace std;
#define DEBUG 0

const int R = 26;

int n;
vector<vector<int>> adj;
bool visited[R];
vector<int> order;

// Adjacency matrix
void make_graph(const vector<string>& words) {
    adj.assign(R, vector<int>(R));
    for (int i = 0; i+1 < words.size(); ++i) {
        int j = i + 1;
        int len = min(words[i].size(), words[j].size());
        for (int k = 0; k < len; ++k) {
            if (words[i][k] == words[j][k]) continue;
            int a = words[i][k] - 'a';
            int b = words[j][k] - 'a';
            adj[a][b] = 1;
            break;
        }
    }
}

void dfs(int u) {
    visited[u] = true;
    for (int v = 0; v < adj.size(); ++v) {
        if (adj[u][v] && visited[v] == false) {
            dfs(v);
        }
    }
    order.push_back(u);
}

vector<int> topo_sort() {
    memset(visited, 0, sizeof visited);
    order.clear();
    for (int i = 0; i < adj.size(); ++i) {
        if (visited[i] == false) {
            dfs(i);
        }
    }
    reverse(order.begin(), order.end());
    for (int i = 0; i < adj.size(); ++i) {
        for (int j = i+1; j < adj.size(); ++j) {
            int a = order[i];
            int b = order[j];
            if (adj[b][a]) {
                return vector<int>();
            }
        }
    }
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
        for (string& s : words) {
            cin >> s;
        }
        make_graph(words);
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
