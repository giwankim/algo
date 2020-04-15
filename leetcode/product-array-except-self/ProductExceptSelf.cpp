#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    size_t n = nums.size();
    vector<int> prefix(n, 1), suffix(n, 1), product(n);
    prefix[0] = 1;
    for (size_t i = 1; i < n; ++i) {
        prefix[i] = prefix[i-1] * nums[i-1];
    }
    suffix[n-1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        suffix[i] = suffix[i+1] * nums[i+1];
    }
    for (size_t i = 0; i < n; ++i) {
        product[i] = prefix[i] * suffix[i];
    }
    return product;
}

int main(int argc, char const *argv[]) {
    vector<int> nums {1,2,3,4};
    auto product = productExceptSelf(nums);
    for (size_t i = 0; i + 1 < product.size(); ++i) {
        cout << product[i] << ", ";
    }
    cout << product[product.size()-1] << "\n";
    return 0;
}
