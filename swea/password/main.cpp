/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRUN9KfZ8DFAUo
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
string s;

void get_nums(vector<int>& nums) {
  int len = n / 4;
  for (int i = 0; i < n; i += len) {
    int cur = 0;
    for (int j = i; j < i+len; ++j) {
      cur *= 16;
      if ('0' <= s[j] && s[j] <= '9') {
        cur += s[j] - '0';
      } else {
        cur += (s[j]-'A') + 10;
      }
    }
    nums.push_back(cur);
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> n >> k;
    cin >> s;
    vector<int> nums;
    get_nums(nums);
    for (int i = 0; i < n/4 - 1; ++i) {
      rotate(s.rbegin(), s.rbegin()+1, s.rend());
      get_nums(nums);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    reverse(nums.begin(), nums.end());
    cout << "#" << t << " " << nums[k-1] << "\n";
  }
}
