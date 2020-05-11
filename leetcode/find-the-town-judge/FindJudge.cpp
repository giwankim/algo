#include "bits/stdc++.h"
using namespace std;

int findJudge(int N, vector<vector<int>> &trust)
{
    vector<int> in(N + 1), out(N + 1);
    for (auto v : trust)
    {
        int a = v[0], b = v[1];
        ++out[a];
        ++in[b];
    }
    for (int i = 1; i <= N; ++i)
    {
        if (in[i] == N - 1 && out[i] == 0)
            return i;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    {
        int N = 2;
        vector<vector<int>> trust = { {1, 2} };
        cout << findJudge(N, trust) << endl;  // 2
    }
    {
        int N = 3;
        vector<vector<int>> trust = { {1, 3}, {2, 3} };
        cout << findJudge(N, trust) << endl;  // 3
    }
    {
        int N = 3;
        vector<vector<int>> trust = { {1, 3}, {2, 3}, {3, 1} };
        cout << findJudge(N, trust) << endl;  // -1
    }
    {
        int N = 3;
        vector<vector<int>> trust = { {1, 2}, {2, 3} };
        cout << findJudge(N, trust) << endl;  // -1
    }
    {
        int N = 4;
        vector<vector<int>> trust = { {1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3} };
        cout << findJudge(N, trust) << endl;  // 3
    }
    return 0;
}
