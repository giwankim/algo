#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, t[1500000], p[1500000];
ll d[1500050];

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t[i] >> p[i];
  }
  for (int i = 0; i < n; ++i) {
    d[i+1] = max(d[i], d[i+1]);
    d[i + t[i]] = max(d[i + t[i]], d[i] + p[i]);
  }
  cout << d[n] << '\n';
}
