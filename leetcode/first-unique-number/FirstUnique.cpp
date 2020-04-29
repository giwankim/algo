#include "bits/stdc++.h"
using namespace std;

class FirstUnique
{
private:
    queue<int> q;
    unordered_map<int, int> cnts;

public:
    FirstUnique(vector<int> &nums)
    {
        for (int x : nums)
            add(x);
    }

    int showFirstUnique()
    {
        while (!q.empty() && cnts[q.front()] > 1) {
            q.pop();
        }
        return q.empty() ? -1 : q.front();
    }

    void add(int value)
    {
        if (++cnts[value] == 1)
            q.push(value);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> nums = {2,3,5};
    FirstUnique fu(nums);
    assert(fu.showFirstUnique() == 2);
    fu.add(5);
    assert(fu.showFirstUnique() == 2);
    fu.add(2);
    assert(fu.showFirstUnique() == 3);
    fu.add(3);
    assert(fu.showFirstUnique() == -1);
    return 0;
}
