#include "bits/stdc++.h"
using namespace std;

class RandomPick
{
private:
    int n;
    mt19937 rng;
    uniform_int_distribution<int> dist;
    vector<int> cums;

public:
    RandomPick(vector<int> &w)
    {
        n = (int)w.size();
        cums.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            cums[i] = cums[i - 1] + w[i - 1];
        }
        random_device rd;
        rng = mt19937(rd());
        dist = uniform_int_distribution<int>(0, cums[n] - 1);
    }

    int pickIndex()
    {
        int targ = dist(rng);
        auto it = upper_bound(cums.begin(), cums.end(), targ);
        return it - cums.begin() - 1;
    }
};

int main(int argc, char const *argv[])
{
    const int num_examples = 1000;

    {
        vector<int> w{3, 5, 7};
        RandomPick rpick(w);
        vector<int> cnts(w.size());
        for (int i = 0; i < num_examples; ++i)
        {
            cnts[rpick.pickIndex()] += 1;
        }
        cout << "===== "
             << "Example 1"
             << " =====\n";
        cout << "Expected:\n\t";
        int tot = accumulate(w.begin(), w.end(), 0);
        for (int x : w)
        {
            cout << (double)x / tot << " ";
        }
        cout << "\n\nObserved:\n\t";
        for (int x : cnts)
        {
            cout << (double)x / num_examples << " ";
        }
        cout << "\n";
    }

    {
        vector<int> w{1, 3};
        RandomPick rpick(w);
        vector<int> cnts(w.size());
        for (int i = 0; i < num_examples; ++i)
        {
            cnts[rpick.pickIndex()] += 1;
        }
        cout << "===== "
             << "Example 2"
             << " =====\n";
        cout << "Expected:\n\t";
        int tot = accumulate(w.begin(), w.end(), 0);
        for (int x : w)
        {
            cout << (double)x / tot << " ";
        }
        cout << "\n\nObserved:\n\t";
        for (int x : cnts)
        {
            cout << (double)x / num_examples << " ";
        }
        cout << "\n";
    }
    return 0;
}
