/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeUtVakTMDFAVH
*/
#include <bits/stdc++.h>
using namespace std;

int n, s[16][16], ans;
vector<int> a, b;

int go(int i) {
  if (i == n) {
    if (a.size() != n/2 || b.size() != n/2) return -1;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n/2; ++i) {
      for (int j = 0; j < n/2; ++j) {
        if (i == j) continue;
        s1 += s[a[i]][a[j]];
        s2 += s[b[i]][b[j]];
      }
    }
    return abs(s1 - s2);
  }
  a.push_back(i);
  int ans = go(i+1);
  a.pop_back();
  b.push_back(i);
  int tmp = go(i+1);
  b.pop_back();
  if (tmp != -1) {
    if (ans == -1 || tmp < ans) {
      ans = tmp;
    }
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> s[i][j];
      }
    }
    a.clear();
    b.clear();
    cout << "#" << t << " " << go(0) << "\n";    
  }
}