#include "bits/stdc++.h"
using namespace std;

class RandomPick {
private:
    int n;
    default_random_engine rng;
    uniform_int_distribution<int> dist;
    vector<int> cumsum;

public:
    RandomPick(vector<int> &w) {
        n = (int)w.size();
        cumsum.assign(n, 0);
        cumsum[0] = w[0];
        for (int i = 1; i < n; ++i) {
            cumsum[i] = cumsum[i-1] + w[i];
        }
        rng = default_random_engine(random_device{}());
        dist = uniform_int_distribution<int>(1, cumsum[n-1]);
    }

    int pickIndex() {
        int targ = dist(rng);
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (cumsum[i] > targ) {
                break;
            }
            ans = i;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    {
        vector<int> w {1, 3};
        RandomPick rpick(w);
        for (int i = 0; i < 10; ++i) {
            cout << rpick.pickIndex() << " ";
        }
        cout << endl;
    }
    return 0;
}

