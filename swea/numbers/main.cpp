/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeRZV6kBUDFAVH
*/
#include <bits/stdc++.h>
using namespace std;

int n, a[12], b[4], x, y;

void go(int i, int cur, int plus, int minus, int mult, int div) {
  if (i == n) {
    x = min(x, cur);
    y = max(y, cur);
    return;
  }
  if (plus > 0) {
    go(i+1, cur+a[i], plus-1, minus, mult, div);
  }
  if (minus > 0) {
    go(i+1, cur-a[i], plus, minus-1, mult, div);
  }
  if (mult > 0) {
    go(i+1, cur*a[i], plus, minus, mult-1, div);
  }
  if (div > 0) {
    go(i+1, cur/a[i], plus, minus, mult, div-1);
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> n;
    int plus, minus, mult, div;
    cin >> plus >> minus >> mult >> div;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    x = 100000000;
    y = -100000000;
    go(1, a[0], plus, minus, mult, div);
    cout << "#" << t << " " << y - x << "\n";
  }
}