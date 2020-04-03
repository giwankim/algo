#include <iostream>
#include <unordered_set>
using namespace std;

bool isHappy(int n) {
    unordered_set<long long> loop;
    while (n != 1) {
        long long m = 0;
        while (n) {
            m += (n % 10) * (n % 10);
            n /= 10;
        }
        if (loop.count(m)) return false;
        loop.insert(m);
        n = m;
    }
    return true;
}

int main() {
    #ifndef online_judge
    fropen();
    #endif
    cout << isHappy(19) << '\n';
    return 0;
}
