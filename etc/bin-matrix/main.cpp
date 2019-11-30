#include <iostream>
#include <vector>
using namespace std;

bool valid(const vector<int>& c, const vector<int>& r) {
  int n = r.size(), m = c.size();
  int csum = 0, rsum = 0, cmax = -1, rmax = -1, nzr = 0, nzc = 0;
  for (int i = 0; i < n; ++i) {
    rsum += r[i];
    if (r[i] > 0) nzr += 1;
    if (rmax == -1 || rmax < r[i]) {
      rmax = r[i];
    }
  }
  for (int j = 0; j < m; ++j) {
    csum += c[j];
    if (c[j] > 0) nzc += 1;
    if (cmax == -1 || cmax < c[j]) {
      cmax = c[j];
    }
  }
  if (rsum != csum) return false;
  if (rmax > nzc) return false;
  if (cmax > nzr) return false;
  return true;
}

int main() {
  vector<int> r = {2,2,2,2,2};
  vector<int> c = {5,5,0,0};
  if (valid(c, r)) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
}