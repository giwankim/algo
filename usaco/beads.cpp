/*
ID: giwanki1
TASK: beads
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
  ifstream fin ("beads.in");
  ofstream fout ("beads.out");
  fin >> n;
  fin >> s;
  int ans = 0;
  for (int i = 0; i < s.size(); ++i) {
    string t = s;
    rotate(t.begin(), t.begin()+i, t.end());
    int cur = 0, j = 1;
    char c = t[0];
    while (j < t.size()) {
      if (c != 'w' && t[j] != c && t[j] != 'w') {
        break;
      }
      if (t[j] != 'w') c = t[j];
      ++j;
    }
    cur += j;
    reverse(t.begin(), t.end());
    c = t[0];
    j = 1;
    while (j < t.size()) {
      if (c != 'w' && t[j] != c && t[j] != 'w') {
        break;
      }
      if (t[j] != 'w') c = t[j];
      ++j;
    }
    cur += j;
    if (cur > n) cur = n;
    ans = max(ans, cur);
  }
  fout << ans << "\n";
}
