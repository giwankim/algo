#include "bits/stdc++.h"
using namespace std;

const int SIZE = 5;
const int dx[] = {-1,-1,-1,0,0,1,1,1};
const int dy[] = {-1,0,1,-1,1,-1,0,1};

struct tuple_hash {
    size_t operator()(const tuple<int, int, string>& tup) const {
        return hash<int>{}(get<0>(tup)) ^ hash<int>{}(get<1>(tup)) ^ hash<string>{}(get<2>(tup));
    }
};

int c, n;
vector<string> board(SIZE);
unordered_map<tuple<int, int, string>, bool, tuple_hash> cache;

bool inRange(int y, int x) {
    return y >= 0 && y < SIZE && x >= 0 && x < SIZE; 
}

bool hasWord(int y, int x, string word) {
    if (cache.find(make_tuple(y, x, word)) != cache.end())
        return cache[make_tuple(y, x, word)];
    if (board[y][x] != word[0])
        return false;
    if ((int)word.size() == 1)
        return true;
    bool ans = false;
    for (int dir = 0; dir < 8; ++dir) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (!inRange(ny, nx))
            continue;
        if (hasWord(ny, nx, word.substr(1))) {
            ans = true;
            break;
        }
    }
    return cache[make_tuple(y, x, word)] = ans;
}

int main(int argc, char const *argv[]) {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin >> c;
    while (c--) {
        cache.clear();
        for (int i = 0; i < SIZE; ++i) {
            cin >> board[i];
        }
        cin >> n;
        while (n--) {
            string word;
            cin >> word;
            bool flag = false;
            for (int y = 0; y < SIZE; ++y) {
                for (int x = 0; x < SIZE; ++x) {
                    if (hasWord(y, x, word)) {
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
            cout << word << " ";
            cout << (flag ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}
