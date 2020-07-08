#include "bits/stdc++.h"
using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int islandPerimeter(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int rows = grid.size();
    int cols = grid[0].size();
    int ret = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                ret += 4;
                for (int k = 0; k < 4; ++k) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (ny < 0 || ny >= rows || nx < 0 || nx >= cols) continue;
                    ret -= grid[ny][nx];
                }
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        vector<vector<int>> grid{{0,1,0,0}, {1,1,1,0}, {0,1,0,0}, {1,1,0,0}};
        int result = islandPerimeter(grid);
        int correct_result = 16;
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
    }
    return 0;
}
