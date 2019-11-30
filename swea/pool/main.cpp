/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpFQaAQMDFAUq
*/
#include <bits/stdc++.h>
#define INF 9999999
using namespace std;

int a[13], p[4];

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> p[0] >> p[1] >> p[2] >> p[3];
    for (int i = 0; i < 12; ++i) {
      cin >> a[i];
    }
    vector<int> d(15, INF);
    d[0] = 0;
    for (int i = 0; i < 12; ++i) {
      d[i+1] = min(d[i+1], a[i]*p[0] + d[i]);
      d[i+1] = min(d[i+1], p[1] + d[i]);
      d[i+3] = min(d[i+3], p[2] + d[i]);
    }

    cout << "#" << t << " " << min(p[3], d[12]) << "\n";
  }
}