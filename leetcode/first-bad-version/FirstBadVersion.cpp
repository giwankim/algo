#include <iostream>
using namespace std;

class FirstBadVersion
{
    int x;

public:
    FirstBadVersion(int x_) : x(x_) {}

    bool isBadVersion(int y) { return y>= x; }

    int firstBadVersion(int n)
    {
        int lo = 1, hi = n;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (isBadVersion(mid) == true)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return lo;
    }
};

int main(int argc, char const *argv[])
{
    FirstBadVersion fbv(4);
    cout << fbv.firstBadVersion(5) << endl;
    return 0;
}
