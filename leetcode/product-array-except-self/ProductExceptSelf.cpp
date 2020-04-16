#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    size_t n = nums.size();
    vector<int> prod(n);
    int prefix = 1;
    for (int i = 0; i < n; ++i) {
        prod[i] = prefix;
        prefix *= nums[i];
    }
    int suffix = 1;
    for (int i = n-1; i >= 0; --i) {
        prod[i] *= suffix;
        suffix *= nums[i];
    }
    return prod;
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
