#include <bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int>& stones)
{
    priority_queue<int> pq(stones.begin(), stones.end());
    while (pq.size() > 1)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        if (x != y)
        {
            pq.push(x - y);
        }
    }
    return pq.empty() ? 0 : pq.top();
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> stones {2,7,4,1,8,1};
    cout << lastStoneWeight(stones) << "\n";
    return 0;
}
