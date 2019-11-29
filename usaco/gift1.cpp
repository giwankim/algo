/*
ID: giwanki1
TASK: gift1
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<string, int> m;

int main() {
  ifstream fin ("gift1.in");
  ofstream fout ("gift1.out");  
  fin >> n;
  vector<string> name(n);
  for (int i = 0; i < n; ++i) {
    string s;
    fin >> s;
    m[s] = 0;
    name[i] = s;
  }
  for (int i = 0; i < n; ++i) {
    string s;
    int x, y;
    fin >> s;
    fin >> x >> y;
    int amt;
    if (y) {
      amt = x / y;
      m[s] += x % y;
    }
    m[s] -= x;
    for (int j = 0; j < y; ++j) {
      string t;
      fin >> t;
      m[t] += amt;
    }
  }
  for (int i = 0; i < n; ++i) {
    fout << name[i] << " " << m[name[i]] << "\n";
  }
}
