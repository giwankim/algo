/*
ID: giwanki1
TASK: namenum
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

char m[10][3] = {
  {' ',' ',' '},
  {' ',' ',' '},
  {'A','B','C'},
  {'D','E','F'},
  {'G','H','I'},
  {'J','K','L'},
  {'M','N','O'},
  {'P','R','S'},
  {'T','U','V'},
  {'W','X','Y'},
};
string s, t;
vector<string> names;
unordered_set<string> dict;

void go(int i) {
  if (i == s.size()) {
    if (dict.find(t) != dict.end()) {
      names.push_back(t);
    }
    return;
  }
  for (int j = 0; j < 3; ++j) {
    t.push_back(m[s[i]-'0'][j]);
    go(i+1);
    t.pop_back();
  }
}

void read_dict() {
  ifstream ifs("dict.txt");
  string word;
  while (ifs >> word) {
    dict.insert(word);
  }
}

int main() {
  ifstream fin("namenum.in");
  ofstream fout("namenum.out");
  fin >> s;
  read_dict();
  go(0);
  for (int i = 0; i < names.size(); ++i) {
    fout << names[i] << "\n";
  }
  if (names.empty()) {
    fout << "NONE" << "\n";
  }
}
