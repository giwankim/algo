/*
ID: giwanki1
TASK: ride
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#define MOD 47
using namespace std;

int val(string& s) {
  int ans = 1;
  for (int i = 0; i < s.size(); ++i) {
    ans *= (s[i]-'A') + 1;
    ans %= MOD;
  }
  return ans;
}

int main() {
  ofstream fout ("ride.out");
  ifstream fin ("ride.in");
  string a, b;
  fin >> a;
  fin >> b;
  if (val(a) == val(b)) {
    fout << "GO";
  } else {
    fout << "STAY";
  }
  fout << endl;
  return 0;
}
