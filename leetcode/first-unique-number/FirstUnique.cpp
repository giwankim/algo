#include "bits/stdc++.h"
using namespace std;

class FirstUnique
{
private:
    list<int> uniqs;
    unordered_map<int, list<int>::iterator> table;
    unordered_set<int> dups;

public:
    FirstUnique(vector<int> &nums)
    {
        for (int x : nums)
            add(x);
    }

    int showFirstUnique()
    {
        return uniqs.empty() ? -1 : uniqs.front();
    }

    void add(int value)
    {
        if (dups.count(value))
            return;
        auto it = table.find(value);
        if (it == table.end()) {
            uniqs.push_back(value);
            table[value] = --uniqs.end();
        } else {
            dups.insert(value);
            uniqs.erase(it->second);
            table.erase(it);
        }
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
