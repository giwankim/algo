#include <cstring>
#include <iostream>
using namespace std;

int d[51][51][51][3][3];

bool go(int a, int b, int c, int p1, int p2) {
  int& ans = d[a][b][c][p1][p2];
  if (a == 0 && b == 0 && c == 0) {
    return ans = true;
  }
  if (ans != -1) return ans;
  if (a > 0 && go(a-1, b, c, 0, p1)) return ans = 1;
  if (b > 0 && p1 != 1 && go(a, b-1, c, 1, p1)) return ans = 1;
  if (c > 0 && p1 != 2 && p2 != 2 && go(a, b, c-1, 2, p1)) return ans = 1;
  return ans = 0;
}

string back(int a, int b, int c, int p1, int p2) {
  if (a == 0 && b == 0 && c == 0) return "";
  if (a > 0 && go(a-1, b, c, 0, p1)) {
    return "A" + back(a-1, b, c, 0, -1);
  }
  if (b > 0 && p1 != 1 && go(a, b-1, c, 1, p1)) {
    return "B" + back(a, b-1, c, 1, p1);
  }
  if (c > 0 && p1 != 2 && p2 != 2 && go(a, b, c-1, 2, p1)) {
    return "C" + back(a, b, c-1, 2, p1);
  }
  return "";
}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif

  string s;
  cin >> s;
  int cnt[3] = {0,};
  for (int i = 0; i < (int)s.length(); ++i) {
    ++cnt[s[i]-'A'];
  }
  memset(d, -1, sizeof d);
  if (go(cnt[0],cnt[1],cnt[2],-1,-1)) {
    cout << back(cnt[0], cnt[1], cnt[2], -1, -1) << '\n';
  } else {
    cout << -1 << '\n';
  }
}
