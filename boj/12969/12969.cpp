#include <iostream>
using namespace std;

int n, k;
bool d[31][31][31][436];
char ans[30];

bool go(int i, int a, int b, int p) {
  if (i == n) {
    return p == k;
  }
  if (d[i][a][b][p]) return false;
  d[i][a][b][p] = true;
  
  ans[i] = 'A';
  if (go(i+1, a+1, b, p)) return true;

  ans[i] = 'B';
  if (go(i+1, a, b+1, p+a)) return true;

  ans[i] = 'C';
  if (go(i+1, a, b, p+a+b)) return true;

  return false;
}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> k;
  if (go(0,0,0,0)) {
    cout << ans << '\n';
  } else {
    cout << -1 << '\n';
  }
}
