#include <iostream>
#include <algorithm>
using namespace std;

string s, t;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  cin >> s >> t;
  while (s.length() != t.length()) {
    if (t.back() == 'A') {
      t.pop_back();
    } else if (t.back() == 'B') {
      t.pop_back();
      reverse(t.begin(), t.end());
    }
  }
  if (s == t) {
    cout << 1 << '\n';
  } else {
    cout << 0 << '\n';
  }
}