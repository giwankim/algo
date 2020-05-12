#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int rows = image.size();
    int cols = image[0].size();
    bool check[51][51];
    memset(check, 0, sizeof check);
    vector<vector<int>> result(image);
    int color = image[sr][sc];
    queue<pair<int, int>> q;
    q.emplace(sr, sc);
    check[sr][sc] = true;
    result[sr][sc] = newColor;
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= rows || ny < 0 || ny >= cols)
                continue;
            if (check[nx][ny])
                continue;
            if (image[nx][ny] == color) {
                q.emplace(nx, ny);
                check[nx][ny] = true;
                result[nx][ny] = newColor;
            }
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    {
        vector<vector<int>> image = {{1,1,1},{1,1,0}, {1,0,1}};
        int sr = 1, sc = 1, newColor = 2;
        auto result = floodFill(image, sr, sc, newColor);
        for (int i = 0; i < result.size(); ++i) {
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
        // 2 2 2 
        // 2 2 0 
        // 2 0 1
    }
    return 0;
}
