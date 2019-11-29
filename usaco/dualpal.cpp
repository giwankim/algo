/*
ID: giwanki1
TASK: dualpal
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

string nconv(int n, int b) {
  string ans;
  while (n) {
    ans += to_string(n % b);
    n /= b;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

bool ispal(const string& s) {
  string t(s);
  reverse(t.begin(), t.end());
  return s == t;
}

int main() {
  ifstream fin ("dualpal.in");
  ofstream fout ("dualpal.out");
  int n, s;
  fin >> n >> s;
  int cnt = 0;
  for (int i = s+1; ; ++i) {
    if (cnt == n) break;
    bool ok = false;
    for (int b = 2; b <= 10; ++b) {
      string t = nconv(i, b);
      if (ispal(t)) {
        if (ok) {
          fout << i << "\n";
          ++cnt;
          break;
        }
        ok = true;
      }
    }
  }
}
