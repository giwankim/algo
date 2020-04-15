#include <bits/stdc++.h>
using namespace std;

string stringShift(string s, vector<vector<int>>& shift) {
    int turns = 0;
    for (size_t i = 0; i < shift.size(); ++i) {
        turns += (shift[i][0] == 0) ? -shift[i][1] : shift[i][1];
    }

    turns %= (int)s.size();

    if (turns > 0) { // right
        rotate(s.begin(), s.begin() + s.size() - turns, s.end());
    } else {         // left
        turns = -turns;
        rotate(s.begin(), s.begin() + turns, s.end());
    }

    return s;
}

int main(int argc, char const *argv[]) {

    /* code */
    vector<vector<int>> shift {{0,1},{1,2}};
    string s = "abc";
    cout << stringShift(s, shift) << "\n";

    shift = {{1, 1}, {1, 1}, {0, 2}, {1, 3}};
    s = "abcdefg";
    cout << stringShift(s, shift) << "\n";

    s = "yisxjwry";
    shift = {{1,8},{1,4},{1,3},{1,6},{0,6},{1,4},{0,2},{0,1}};
    cout << stringShift(s, shift) << "\n";

    s = "wpdhhcj";
    shift = {{0,7},{1,7},{1,0},{1,3},{0,3},{0,6},{1,2}};
    cout << stringShift(s, shift) << "\n";  // hcjwpdh

    return 0;
}
