#include "bits/stdc++.h"
using namespace std;

const int R = 26;

int n;

// adj[i][j] := #edges between vertex i and j
vector<vector<int>> adj;

// edges[i][j] := list of edges (words) from vertex i to vertex j
vector<string> edges[R][R];

vector<int> indeg, outdeg;

void _initialize() {
    adj.resize(R, vector<int>(R));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < R; ++j) {
            edges[i][j].clear();
        }
    }
    indeg.assign(R, 0);
    outdeg.assign(R, 0);
}

void make_graph(const vector<string>& words) {
    _initialize();
    for (int i = 0; i < n; ++i) {
        int a = words[i].front() - 'a';
        int b = words[i].back() - 'a';
        edges[a][b].push_back(words[i]);
        adj[a][b] += 1;
        outdeg[a] += 1;
        indeg[b] += 1;
    }
}

void getEulerCircuit(int from, vector<int>& circuit) {
    for (int to = 0; to < R; ++to) {
        while (adj[from][to] > 0) {
            adj[from][to] -= 1;
            getEulerCircuit(to, circuit);
        }
    }
    circuit.push_back(from);
}

// Assuming Euler circuit or path exists, find it!
vector<int> getEulerTrailOrCircuit() {
    vector<int> circuit;
    // Find Euler path
    for (int i = 0; i < R; ++i) {
        if (outdeg[i] - indeg[i] == 1) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    // Find Euler circuit
    for (int i = 0; i < R; ++i) {
        if (outdeg[i]) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    return circuit;
}

bool checkEuler() {
    int plus1 = 0;
    int minus1 = 0;
    for (int i = 0; i < R; ++i) {
        int delta = outdeg[i] - indeg[i];
        if (delta < -1 || delta > 1) {
            return false;
        }
        if (delta == 1) {
            plus1 += 1;
        } else if (delta == -1) {
            minus1 += 1;
        }
    }
    return (plus1 == 0 && minus1 == 0) || (plus1 == 1 && minus1 == 1);
}

string solve(const vector<string>& words) {
    make_graph(words);
    if (checkEuler() == false) {
        return "IMPOSSIBLE";
    }
    vector<int> circuit = getEulerTrailOrCircuit();
    if (circuit.size() != words.size() + 1) {
        return "IMPOSSIBLE";
    }
    reverse(circuit.begin(), circuit.end());
    string ret;
    for (int i = 0; i+1 < circuit.size(); ++i) {
        int a = circuit[i];
        int b = circuit[i+1];
        if (i > 0) ret += " ";
        ret += edges[a][b].back();
        edges[a][b].pop_back();
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // freopen("log.txt", "w", stderr);
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> n;
        vector<string> words(n);
        for (int i = 0; i < n; ++i) {
            cin >> words[i];
        }
        cout << solve(words) << "\n";
    }
}
