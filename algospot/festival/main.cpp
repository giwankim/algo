#include <bits/stdc++.h>
using namespace std;

int n, l, a[1000];

double go() {
  double ans = 999;
  for (int i = 0; i <= n-l; ++i) {
    int sum = 0;
    for (int j = i; j < n; ++j) {
      sum += a[j];
      int days = j - i + 1;
      if (days >= l) {
        ans = min(ans, (double)sum/days);
      }
    }
  }
  return ans;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    printf("%.11f\n", go());
  }
}