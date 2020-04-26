#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(vector<int> &nums)
{
    if (nums.empty()) return false;
    int max_index = 0;
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (i <= max_index)
            max_index = max(max_index, i + nums[i]);
    }
    return max_index + 1 >= nums.size();
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> nums = {2,3,1,1,4};
    cout << canJump(nums) << "\n";
    nums = {3,2,1,0,4};
    cout << canJump(nums) << "\n";
    return 0;
}
