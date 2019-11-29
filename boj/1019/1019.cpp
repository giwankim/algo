#include <iostream>
using namespace std;
typedef long long ll;

ll cnt[10];

void calc(int n, int ten) {
  while (n) {
    cnt[n % 10] += ten;
    n /= 10;
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
  int start = 1, end, ten = 1;
  cin >> end;
  while (start <= end) {
    while (start % 10 != 0 && start <= end) {
      calc(start++, ten);
    }
    while (end % 10 != 9 && start <= end) {
      calc(end--, ten);
    }
    if (start > end) break;
    int inc = end/10 - start/10 + 1;
    for (int i = 0; i <= 9; ++i) {
      cnt[i] += (ll)inc * ten;
    }
    start /= 10;
    end /= 10;
    ten *= 10;
  }
  for (int i = 0; i <= 9; ++i) {
    cout << cnt[i] << ' ';
  }
  cout << '\n';
}
