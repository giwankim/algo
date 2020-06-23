#include "bits/stdc++.h"
using namespace std;

int n, m;
bool areFriends[10][10];

int countPairs(bool check[10]) {
    int firstFree = -1;
    for (int i = 0; i < n; ++i) {
        if (!check[i]) {
            firstFree = i;
            break;
        }
    }
    if (firstFree == -1) return 1;
    int ans = 0;
    check[firstFree] = true;
    for (int i = firstFree + 1; i < n; ++i) {
        if (check[i] || !areFriends[firstFree][i])
            continue;
        check[i] = true;
        ans += countPairs(check);
        check[i] = false;
    }
    check[firstFree] = false;
    return ans;
}


int main(int argc, char const *argv[]) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> n >> m;
        memset(areFriends, 0, sizeof areFriends);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            areFriends[a][b] = areFriends[b][a] = true;
        }
        bool check[10];
        memset(check, 0, sizeof check);
        cout << countPairs(check) << "\n";
    }
    return 0;
}
