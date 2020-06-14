#include "bits/stdc++.h"
using namespace std;
#define INF 1000000000

void _print(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << "\n";
}

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
    vector<int> dist(n, INF);
    dist[src] = 0;
    for (int k = 0; k <= K; ++k) {
        vector<int> tmp = dist;
        for (auto& flight : flights) {
            int s = flight[0];
            int t = flight[1];
            int w = flight[2];
            tmp[t] = min(tmp[t], dist[s] + w);
        }
        dist = tmp;
        // _print(dist);
    }
    return dist[dst] == INF ? -1 : dist[dst];
}

int main(int argc, char const *argv[])
{
    {
        cout << "=====Example 1=====\n";
        int n = 3;
        vector<vector<int>> flights{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
        int src = 0;
        int dst = 2;
        int K = 1;
        int result = findCheapestPrice(n, flights, src, dst, K);
        int correct_result = 200;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        // assert(result == correct_result);
    }
    {
        cout << "=====Example 2=====\n";
        int n = 3;
        vector<vector<int>> flights{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
        int src = 0;
        int dst = 2;
        int K = 0;
        int result = findCheapestPrice(n, flights, src, dst, K);
        int correct_result = 500;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
        // assert(result == correct_result);
    }
    return 0;
}
