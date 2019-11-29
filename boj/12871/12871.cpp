#include <iostream>
using namespace std;

string s, t;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  cin >> s >> t;
  int n = s.length();
  int m = t.length();
  for (int i = 0; i < n*m; ++i) {
    if (s[i % n] != t[i % m]) {
      cout << 0 << '\n';
      return 0;
    }
  }
  cout << 1 << '\n';
}
