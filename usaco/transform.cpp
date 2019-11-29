/*
ID: giwanki1
TASK: transform
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;

int n;

vector<string> trans1(vector<string> a) {
  vs b(a);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      b[i][j] = a[n-j-1][i];
    }
  }
  return b;
}

vector<string> trans2(vector<string> a) {
  vs b(a);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      b[i][j] = a[n-i-1][n-j-1];
    }
  }
  return b;
}

vs trans3(vs a) {
  vs b(a);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      b[i][j] = a[j][n-i-1];
    }
  }
  return b;
}

vector<string> trans4(vector<string> a) {
  vector<string> b(a);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      b[i][j] = a[i][n-j-1];
    }
  }
  return b;
}

int main() {
  ifstream fin("transform.in");
  ofstream fout("transform.out");
  fin >> n;
  vector<string> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    fin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    fin >> b[i];
  }
  int ans = -1;
  if (b == trans1(a)) {
    ans = 1;
  } else if (b == trans2(a)) {
    ans = 2;
  } else if (b == trans3(a)) {
    ans = 3;
  }
   else if (b == trans4(a)) {
    ans = 4;
  } else if (b == trans1(trans4(a)) || b == trans2(trans4(a)) || b == trans3(trans4(a))) {
    ans = 5;
  } else if (b == a) {
    ans = 6;
  } else {
    ans = 7;
  }
  fout << ans << "\n";
}