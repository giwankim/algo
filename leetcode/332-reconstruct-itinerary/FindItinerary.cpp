#include "bits/stdc++.h"
using namespace std;

unordered_map<string, map<string, int>> adj;
vector<string> path;

void _print(const vector<string> &vec) {
    for (int i = 0; i+1 < vec.size(); ++i)
        cout << vec[i] << ", ";
    if (!vec.empty())
        cout << vec.back();
    cout << "\n";
}

void make_graph(const vector<vector<string>>& tickets) {
    adj.clear();
    for (int i = 0; i < tickets.size(); ++i) {
        string from = tickets[i][0];
        string to = tickets[i][1];
        adj[from][to] += 1;
    }
}

void dfs(const string& from) {
    for (auto it = adj[from].begin(); it != adj[from].end(); ++it) {
        string to = it->first;
        while (adj[from][to] > 0) {
            adj[from][to] -= 1;
            dfs(to);
        }
    }
    path.push_back(from);
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
    path.clear();
    make_graph(tickets);
    dfs("JFK");
    reverse(path.begin(), path.end());
    return path;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        vector<vector<string>> tickets{{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
        vector<string> result = findItinerary(tickets);
        vector<string> correct_result{"JFK", "MUC", "LHR", "SFO", "SJC"};
        cout << "Expected:\n";
        _print(correct_result);
        cout << "Output:\n";
        _print(result);
    }
    {
        cout << "=====Example 2=====\n";
        vector<vector<string>> tickets{{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
        vector<string> result = findItinerary(tickets);
        vector<string> correct_result{"JFK", "ATL", "JFK", "SFO", "ATL", "SFO"};
        cout << "Expected:\n";
        _print(correct_result);
        cout << "Output:\n";
        _print(result);
    }
    {
        cout << "=====Example 3=====\n";
        vector<vector<string>> tickets{
            {"EZE", "AXA"}, {"TIA", "ANU"}, {"ANU", "JFK"}, {"JFK", "ANU"},
            {"ANU", "EZE"}, {"TIA", "ANU"}, {"AXA", "TIA"}, {"TIA", "JFK"},
            {"ANU", "TIA"}, {"JFK", "TIA"},
        };
        vector<string> result = findItinerary(tickets);
        vector<string> correct_result{
            "JFK", "ANU", "EZE", "AXA", "TIA", "ANU",
            "JFK", "TIA", "ANU", "TIA", "JFK",
        };
        cout << "Expected:\n";
        _print(correct_result);
        cout << "Output:\n";
        _print(result);
    }
    {
        cout << "=====Example 4=====\n";
        vector<vector<string>> tickets{
            {"JFK","ATL"}, {"ORD","PHL"}, {"JFK","ORD"}, {"PHX","LAX"},
            {"LAX","JFK"}, {"PHL","ATL"}, {"ATL","PHX"},
        };
        vector<string> result = findItinerary(tickets);
        vector<string> correct_result{"JFK", "ATL", "PHX", "LAX", "JFK", "ORD", "PHL", "ATL"};
        cout << "Expected:\n";
        _print(correct_result);
        cout << "Output:\n";
        _print(result);
    }
    return 0;
}
