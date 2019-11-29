#include <cstring>
#include <iostream>
using namespace std;

int n;
long long cache[31][31];

long long calc(int w, int h) {
  if (cache[w][h] != -1) return cache[w][h];
  if (w == 0) return 1;
  if (h == 0) return cache[w][h] = calc(w-1, h+1);
  return cache[w][h] = calc(w-1, h+1) + calc(w, h-1);
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  memset(cache, -1, sizeof cache);
  while (cin >> n, n) {
    cout << calc(n, 0) << '\n';
  }
}
