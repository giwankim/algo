#include "bits/stdc++.h"
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    for (int i = 0; i < 32; ++i) {
        if (n & (1 << (31 - i))) {
            ret |= 1 << i;
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    {
        cout << "======Example 1=====\n";
        uint32_t n = 43261596;
        uint32_t result = reverseBits(n);
        uint32_t correct_result = 964176192;
        cout << "Expected:\n\t";
        cout << bitset<32>(correct_result).to_string() << "\n";
        cout << "Output:\n\t";
        cout << bitset<32>(result).to_string() << "\n";
    }
    {
        cout << "======Example 2=====\n";
        uint32_t n = 4294967293;
        uint32_t result = reverseBits(n);
        uint32_t correct_result = 3221225471;
        cout << "Expected:\n\t";
        cout << bitset<32>(correct_result).to_string() << "\n";
        cout << "Output:\n\t";
        cout << bitset<32>(result).to_string() << "\n";
    }
    return 0;
}
