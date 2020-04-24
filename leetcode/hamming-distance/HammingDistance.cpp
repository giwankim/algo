#include <iostream>
using namespace std;

int hammingDistance(int x, int y) {
    int z = x ^ y;
    int dist = 0;
    while (z) {
        z &= z - 1;
        dist += 1;
    }
    return dist;
}

int main(int argc, char const *argv[])
{
    cout << hammingDistance(1, 4) << "\n";
    return 0;
}
