#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const int MAX_DAYS = 50;

int c, n, m, cows[1001];
ll T[1001][MAX_DAYS + 1];

void solve()
{
    memset(T, 0, sizeof T);
    for (int i = 1; i <= c; ++i)
    {
        T[i][0] = 1;
    }
    for (int j = 1; j <= MAX_DAYS; ++j)
    {
        for (int i = 1; i <= c; ++i)
        {
            if (2 * i <= c)
            {
                T[i][j] = T[2 * i][j - 1];
            }
            else
            {
                T[i][j] = 2 * T[i][j - 1];
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    freopen("02.in", "r", stdin);
    freopen("02.out", "w", stdout);

    scanf("%d %d %d", &c, &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &cows[i]);
    }
    solve();
    for (int i = 0; i < m; ++i)
    {
        int day;
        scanf("%d", &day);
        ll ans = 0;
        for (int j = 0; j < n; ++j)
        {
            ans += T[cows[j]][day];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
