#include "bits/stdc++.h"
using namespace std;

int SearchFirstOfK(const vector<int> &A, int k)
{
    // Takes a sorted array and key and returns the index of the
    // first occurence of that key in the array.
    int lo = 0, hi = A.size() - 1, ans = -1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (A[mid] == k)
        {
            ans = mid;
            hi = mid - 1;
        }
        if (A[mid] < k)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return ans;
}

void TestCase(const vector<int> &A, int k)
{
    int result = SearchFirstOfK(A, k);
    auto it = find(A.begin(), A.end(), k);
    int correct_result = distance(A.begin(), it);
    if (it == A.end())
    {
        assert(result == -1);
    }
    else
    {
        assert(result == correct_result);
    }
}

static void SimpleTest()
{
    cout << "Running simple tests...\n"
    vector<int> A = {0, 1, 2, 3, 4, 5, 6, 7};
    assert(0 == SearchFirstOfK(A, 0));
    assert(1 == SearchFirstOfK(A, 1));
    assert(4 == SearchFirstOfK(A, 4));
    assert(6 == SearchFirstOfK(A, 6));
    assert(7 == SearchFirstOfK(A, 7));
    assert(-1 == SearchFirstOfK(A, 8));
    assert(-1 == SearchFirstOfK(A, numeric_limits<int>::min()));
    A[0] = 1;
    assert(0 == SearchFirstOfK(A, 1));
    A[5] = 4;
    A[6] = 4;
    assert(4 == SearchFirstOfK(A, 4));
    A = {1, 1, 1, 1, 1, 2};
    assert(-1 == SearchFirstOfK(A, 0));
    assert(0 == SearchFirstOfK(A, 1));
    assert(5 == SearchFirstOfK(A, 2));
    A[4] = 2;
    assert(4 == SearchFirstOfK(A, 2));
}

int main(int argc, char const *argv[])
{
    // Simple test cases
    SimpleTest();

    // Test with random input
    const int num_tests = 1000;
    const int max_A_size = 100000;
    random_device rd;
    default_random_engine rng(rd());

    for (int t = 0; t < num_tests; ++t)
    {
        uniform_int_distribution<int> n_dist(1, max_A_size);
        int n = n_dist(rng);

        uniform_int_distribution<int> k_dist(0, n - 1);
        int k = k_dist(rng);

        vector<int> A(n);
        uniform_int_distribution dist(0, n - 1);
        for (int &x : A)
        {
            x = dist(rng);
        }
        sort(A.begin(), A.end());
        TestCase(A, k);
    }
    return 0;
}
