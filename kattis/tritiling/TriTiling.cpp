#include "bits/stdc++.h"
using namespace std;

int n;
long long T[30][8];

int main(int argc, char const *argv[])
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    memset(T, 0, sizeof T);
    T[0][0] = T[0][3] = T[0][6] = 1;
    for (int i = 1; i < 30; ++i) {
        T[i][0] = T[i-1][7];
        T[i][1] = T[i-1][6];
        T[i][2] = T[i-1][5];
        T[i][3] = T[i-1][4] + T[i-1][7];
        T[i][4] = T[i-1][3];
        T[i][5] = T[i-1][2];
        T[i][6] = T[i-1][1] + T[i-1][7];
        T[i][7] = T[i-1][0] + T[i-1][3] + T[i-1][6];
    }
    while (scanf("%d", &n), n != -1) {
        printf("%lld\n", n == 0 ? 1 : T[n-1][7]);
    }
    return 0;
}
