#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class BinaryMatrix {
public:
    vector<vector<int>> data;
    BinaryMatrix(vector<vector<int>> data_) : data(data_) {}
    vector<int> dimensions() { return {(int)data.size(), (int)data[0].size()}; }
    int get(int x, int y) { return data[x][y]; }
};

int leftMostColumnWithOne(BinaryMatrix& binaryMatrix) {
    vi dims = binaryMatrix.dimensions();
    int n = dims[0], m = dims[1];
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        int lo = 0, hi = m-1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (binaryMatrix.get(i, mid) == 1) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if (binaryMatrix.get(i, lo) == 1) {
            if (ans == -1 || lo < ans)
                ans = lo;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> data {{0,0},{1,1}};
    BinaryMatrix bm(data);
    cout << leftMostColumnWithOne(bm) << "\n";  // 0

    bm.data = {{0,0},{0,1}};
    cout << leftMostColumnWithOne(bm) << "\n";  // 1

    bm.data = {{0,0}, {0,0}};
    cout << leftMostColumnWithOne(bm) << "\n";  // -1

    bm.data = {{0,0,0,1}, {0,0,1,1}, {0,1,1,1}};
    cout << leftMostColumnWithOne(bm) << "\n";  // 1
    return 0;
}
