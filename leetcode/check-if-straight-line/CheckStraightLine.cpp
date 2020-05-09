#include "bits/stdc++.h"
using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates) {
    int x0 = coordinates[0][0], y0 = coordinates[0][1];
    int dx0 = coordinates[1][0] - x0;
    int dy0 = coordinates[1][1] - y0;
    for (int i =  2; i < (int)coordinates.size(); ++i) {
        int dx1 = coordinates[i][0] - x0;
        int dy1 = coordinates[i][1] - y0;
        if (dx0 * dy1 - dx1 * dy0 != 0)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    {
        vector<vector<int>> coordinates = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
        cout << checkStraightLine(coordinates) << endl;  // true
    }

    {
        vector<vector<int>> coordinates = {{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};
        cout << checkStraightLine(coordinates) << endl;  // false
    }
    return 0;
}
