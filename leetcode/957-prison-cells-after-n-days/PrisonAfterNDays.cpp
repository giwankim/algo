#include "bits/stdc++.h"
using namespace std;

void _print(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";
}

int vec2int(const vector<int>& v) {
    int ret = 0;
    for (int x : v) {
        ret <<= 1;
        ret = (ret | x);
    }
    return ret;
}

vector<int> NextCells(const vector<int>& cells) {
    int n = cells.size();
    vector<int> ret(cells.size());
    ret[0] = ret[n-1] = 0;
    for (int i = 1; i+1 < n; ++i) {
        if (cells[i-1] == cells[i+1]) {
            ret[i] = 1;
        } else {
            ret[i] = 0;
        }
    }
    return ret;
}

vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    unordered_map<int, int> cache;
    bool ff = false;
    while (N) {
        if (ff == false) {
            int state = vec2int(cells);
            if (cache.find(state) != cache.end()) {
                int cycle_len = cache[state] - N;
                N %= cycle_len;
                ff = true;
            } else {
                cache[state] = N;
            }
        }
        if (N) {
            cells = NextCells(cells);
            N -= 1;
        }
    }
    return cells;
}

int main(int argc, char const *argv[])
{
    {
        cout << "=====Example 1=====\n";
        int n = 7;
        vector<int> cells{0, 1, 0, 1, 1, 0, 0, 1};
        vector<int> result = prisonAfterNDays(cells, n);
        vector<int> correct_result{0, 0, 1, 1, 0, 0, 0, 0};
        cout << "Expected:\n\t";
        _print(correct_result);
        cout << "Output:\n\t";
        _print(result);
    }
    {
        cout << "=====Example 2=====\n";
        int n = 1000000000;
        vector<int> cells{1, 0, 0, 1, 0, 0, 1, 0};
        vector<int> result = prisonAfterNDays(cells, n);
        vector<int> correct_result{0, 0, 1, 1, 1, 1, 1, 0};
        cout << "Expected:\n\t";
        _print(correct_result);
        cout << "Output:\n\t";
        _print(result);
    }
    {
        cout << "=====Example 3=====\n";
        int n = 6;
        vector<int> cells{1, 1, 0, 1, 1, 0, 1, 1};
        vector<int> result = prisonAfterNDays(cells, n);
        vector<int> correct_result{0, 0, 1, 1, 1, 1, 1, 0};
        cout << "Expected:\n\t";
        _print(correct_result);
        cout << "Output:\n\t";
        _print(result);
    }
    // vector<int> cells{0, 1, 0, 1, 1, 0, 0, 1};
    // unordered_map<int, int> cache;
    // for (int i = 0; i < 20; ++i) {
    //     if (i < 10) {
    //         cout << " " << i << ": ";    
    //     } else {
    //         cout << i << ": ";
    //     }
    //     _print(cells);
    //     int state = vec2int(cells);
    //     if (cache.find(state) != cache.end()) {
    //         cout << "Found " << "\n";
    //     }
    //     cache[state] = i;
    //     cells = NextCells(cells);
    return 0;
}
