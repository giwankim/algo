#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

const int mod = 1000000007;
int n, m, p;
ll d[101][101];

ll go(int i, int x) {
  if (i == p) {
    return x == n;
  }
  if (x > n) return 0;
  ll& ans = d[i][x];
  if (ans != -1) return ans;
  ans = (n - x) * go(i+1, x+1);
  ans %= mod;
  if (x > m) {
    ans += (x - m) * go(i+1, x);
    ans %= mod;
  }
  return ans;
}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  cin >> n >> m >> p;
  memset(d, -1, sizeof d);
  cout << go(0, 0) << '\n';
}
