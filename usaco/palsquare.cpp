/*
ID: giwanki1
TASK: palsquare
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

int b;

string go(int n) {
  string ans;
  while (n) {
    if (n % b < 10) {
      ans += to_string(n % b);
    } else {
      ans += (n % b) - 10 + 'A';
    }
    n /= b;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  ifstream fin ("palsquare.in");
  ofstream fout ("palsquare.out");
  fin >> b;
  for (int i = 1; i <= 300; ++i) {
    int n = i * i;
    string a = go(n);
    string b(a.rbegin(), a.rend());
    if (a == b) {
      fout << go(i) << " " << a << "\n";
    }
  }
}
