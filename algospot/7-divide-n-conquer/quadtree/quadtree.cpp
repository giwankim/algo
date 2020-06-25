#include "bits/stdc++.h"
using namespace std;


const int MAX_SIZE = 1024;
char board[MAX_SIZE][MAX_SIZE];

// decompress s covering board[y:y+size][x:x+size] 
void Decompress(string::iterator& it, int y, int x, int size) {
    char head = *(it++);
    if (head == 'w' || head == 'b') {
        for (int dy = 0; dy < size; ++dy) {
            for (int dx = 0; dx < size; ++dx) {
                board[y+dy][x+dx] = head;
            }
        }
    } else {
        int half = size / 2;
        Decompress(it, y, x, half);
        Decompress(it, y, x+half, half);
        Decompress(it, y+half, x, half);
        Decompress(it, y+half, x+half, half);
    }
}

string Flip(string::iterator& it) {
    char head = *(it++);
    // Reached terminal nodes in the quadtree
    if (head == 'b' || head == 'w') {
        return string(1, head);
    }
    string ul = Flip(it);
    string ur = Flip(it);
    string ll = Flip(it);
    string lr = Flip(it);
    return "x" + ll + lr + ul + ur;
}

int main(int argc, char const *argv[]) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
    int cases;
    cin >> cases;
    while (cases--) {
        string s;
        cin >> s;
        string::iterator it = s.begin();
        cout << Flip(it) << "\n";
    }
    return 0;
}
