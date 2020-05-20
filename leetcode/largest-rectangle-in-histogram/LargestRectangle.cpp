#include "bits/stdc++.h"
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    stack<int> s;
    s.push(-1);
    int max_area = 0;
    for (int i = 0; i < (int)heights.size(); ++i)
    {
        while (s.top() != -1 && heights[i] < heights[s.top()])
        {
            int height = heights[s.top()];
            s.pop();
            int base = i - s.top() - 1;
            int area = height * base;
            max_area = max(max_area, area);
        }
        s.push(i);
    }
    while (s.top() != -1)
    {
        int height = heights[s.top()];
        s.pop();
        int base = heights.size() - s.top() - 1;
        int area = height * base;
        max_area = max(max_area, area);
    }
    return max_area;
}

int main(int argc, char const *argv[])
{
    {
        vector<int> heights{};
        cout << largestRectangleArea(heights) << endl; // 0
    }
    {
        vector<int> heights{0};
        cout << largestRectangleArea(heights) << endl; // 0
    }
    {
        vector<int> heights{2, 1, 5, 6, 2, 3};
        cout << largestRectangleArea(heights) << endl; // 10
    }
    {
        vector<int> heights{1, 2, 3, 4, 5};
        cout << largestRectangleArea(heights) << endl; // 9
    }

    {
        vector<int> heights{2, 1, 1, 1};
        cout << largestRectangleArea(heights) << endl; // 4
    }
    {
        vector<int> heights{2, 1, 2};
        cout << largestRectangleArea(heights) << endl; // 3
    }
    return 0;
}
