/*
ID: giwanki1
TASK: milk2
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  ifstream fin ("milk2.in");
  ofstream fout ("milk2.out");
  fin >> n;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; ++i) {
    int x, y;
    fin >> x >> y;
    a.emplace_back(x, y);
  }
  sort(a.begin(), a.end());
  int s = a[0].first, e = a[0].second, ans1, ans2 = 0;
  ans1 = e - s;
  for (int i = 1; i < a.size(); ++i) {
    if (i == 0 || a[i].first <= e) {
      e = max(e, a[i].second);
      ans1 = max(ans1, e - s);
    } else {
      ans2 = max(ans2, a[i].first - e);
      tie(s, e) = a[i];
    }
  }
  ans1 = max(ans1, e - s);
  fout << ans1 << " " << ans2 << "\n";
}
