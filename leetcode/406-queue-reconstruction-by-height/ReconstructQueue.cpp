#include "bits/stdc++.h"
using namespace std;

void print_(const vector<vector<int>> &arr)
{
    for (auto &p : arr)
    {
        cout << "(" << p[0] << "," << p[1] << ") ";
    }
    cout << endl;
}

vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
{
    sort(people.begin(), people.end(), [](const auto &lhs, const auto &rhs) {
        return lhs[0] == rhs[0] ? lhs[1] < rhs[1] : lhs[0] > rhs[0];
    });
    list<vector<int>> ll;
    for (auto &p : people)
    {
        auto it = ll.begin();
        advance(it, p[1]);
        ll.insert(it, p);
    }
    return vector<vector<int>>(ll.begin(), ll.end());
}

int main(int argc, char const *argv[])
{
    {
        cout << "===== "
             << "Example 1"
             << " =====\n";
        vector<vector<int>> people{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
        vector<vector<int>> result = reconstructQueue(people);
        print_(result);
        // (5,0) (7,0) (5,2) (6,1) (4,4) (7,1)

        vector<vector<int>> correct_result = {
            {5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}};
        assert(std::equal(result.begin(), result.end(), correct_result.begin()));
    }

    {
        cout << "\n===== "
             << "Example 2"
             << " =====\n";
        vector<vector<int>> people{
            {2, 4}, {3, 4}, {9, 0}, {0, 6}, {7, 1}, {6, 0}, {7, 3}, {2, 5}, {1, 1}, {8, 0}};
        vector<vector<int>> result = reconstructQueue(people);
        print_(result);
        // {{6,0}, {1,1}, {8,0}, {7,1}, {9,0}, {2,4}, {0,6}, {2,5}, {3,4}, {7,3}}

        vector<vector<int>> correct_result = {
            {6, 0}, {1, 1}, {8, 0}, {7, 1}, {9, 0}, {2, 4}, {0, 6}, {2, 5}, {3, 4}, {7, 3}};
        assert(std::equal(result.begin(), result.end(), correct_result.begin()));
    }
    return 0;
}
