/*
ID: giwanki1
TASK: friday
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int n, cnt[7];


bool is_leap(int y) {
  if (y % 100 == 0) {
    return y % 400 == 0;
  }
  return y % 4 == 0;
}

int main() {
  ifstream fin("friday.in");
  ofstream fout("friday.out");
  fin >> n;
  int day = 5;
  for (int i = 0; i < n; ++i) {
    int y = 1900 + i;
    for (int j = 0; j < 12; ++j) {
      ++cnt[day];
      if (j == 1 && is_leap(y)) {
        day += 29 % 7;
      } else {
        day += days[j] % 7;
      }
      day %= 7;
    }
  }
  fout << cnt[5] << " " << cnt[6] << " ";
  for (int i = 0; i < 4; ++i) {
    fout << cnt[i] << " ";
  }
  fout << cnt[4] << "\n";
}
