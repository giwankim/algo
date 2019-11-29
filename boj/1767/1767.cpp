#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

const int mod = 1000001;
ll d[101][101][101];

ll go(int n, int m, int k) {
  if (k == 0) return 1;
  if (n <= 0 || m <= 0 || k < 0) return 0;
  ll& ans = d[n][m][k];
  if (ans != -1) return ans;
  ans = go(n-1, m, k) + go(n-1, m-1, k-1) * m;
  ans += go(n-2, m-1, k-2) * m*(n-1) + go(n-1, m-2, k-2) * m*(m-1)/2;
  ans %= mod;
  return ans;
}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int n, m, k;
  cin >> n >> m >> k;
  memset(d, -1, sizeof d);
  cout << go(n, m, k) << '\n';
}
