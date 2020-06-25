#include "bits/stdc++.h"
using namespace std;

void normalize(vector<int>& num) {
    // num.push_back(0);
    // for (int i = 0; i+1 < (int)num.size(); ++i) {
    //     if (num[i] < 0) {
    //         int borrow = abs(num[i] + 9) / 10;
    //         num[i+1] -= borrow;
    //         num[i] += borrow * 10;
    //     } else {
    //         num[i+1] += num[i] / 10;
    //         num[i] %= 10;
    //     }
    // }
    // while (num.size() > 1 && num.back() == 0) num.pop_back();
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size() + b.size() + 1);
    for (int i = 0; i < (int)a.size(); ++i) {
        for (int j = 0; j < (int)b.size(); ++j) {
            c[i+j] += a[i] * b[j];
        }
    }
    normalize(c);
    return c;
}

// a+= b * (10^k)
void addTo(vector<int>& a, const vector<int>& b, int k) {
    a.resize(max(a.size(), b.size() + k));
    for (int i = 0; i < (int)b.size(); ++i) {
        a[i+k] += b[i];
    }
    normalize(a);
}

// a -= b; assume a >= b
void subFrom(vector<int>& a, const vector<int>& b) {
    // a.resize(max(a.size(), b.size()) + 1);
    for (int i = 0; i < (int)b.size(); ++i) {
        a[i] -= b[i];
    }
    normalize(a);
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    int an = (int)a.size(), bn = (int)b.size();
    if (an < bn)
        return karatsuba(b, a);
    if (an == 0 || bn == 0)
        return vector<int>();
    if (an <= 50)
        return multiply(a, b);

    int half = an / 2;
    // a = a1 * 10^half + a0
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    // b = b1 * 10^half + b0
    vector<int> b0(b.begin(), b.begin() + min<int>(half, b.size()));
    vector<int> b1(b.begin() + min<int>(half, b.size()), b.end());

    // z2 = a1 * b1
    vector<int> z2 = karatsuba(a1, b1);
    // z0 = a0 * b0
    vector<int> z0 = karatsuba(a0, b0);
    // a0 += a1; b0 += b1
    addTo(a0, a1, 0);
    addTo(b0, b1, 0);
    // z1 = a0 * b0 - z0 - z2
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    // ret = z0 + z1 * 10^half + z2 * 10^2*half
    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);
    return ret;
}

int BruteForce(const string& members, const string& fans) {
    int n = (int)fans.size();
    int m = (int)members.size();
    assert(m <= n);
    int hugs = 0;
    for (int i = 0; i < n - m + 1; ++i) {
        bool ok = true;
        for (int j = 0; j < m; ++j) {
            if (members[j] == 'M' && fans[i+j] == 'M') {
                ok = false;
                break;
            }
        }
        if (ok) hugs += 1;
    }
    return hugs;
}

int Hugs(const string& members, const string& fans) {
    int n = (int)members.size();
    int m = (int)fans.size();
    vector<int> A(n);
    vector<int> B(m);
    for (int i = 0; i < n; ++i) {
        A[i] = members[i] == 'M' ? 1 : 0;
    }
    for (int i = 0; i < m; ++i) {
        B[m-i-1] = fans[i] == 'M' ? 1 : 0;
    }
    vector<int> C = karatsuba(A, B);
    int ret = 0;
    for (int i = n-1; i < m; ++i) {
        if (C[i] == 0) {
            ret += 1;
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases;
    cin >> cases;
    while (cases--) {
        string members, fans; 
        cin >> members;
        cin >> fans;
        cout << Hugs(members, fans) << "\n";
        // assert(Hugs(members, fans) == BruteForce(members, fans));
    }
    return 0;
}
