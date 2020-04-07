#include <bits/stdc++.h>
using namespace std;

int countElements(vector<int> &arr)
{
    unordered_set<int> set;
    for (int x : arr)
    {
        set.insert(x);
    }
    int cnt = 0;
    for (int x : arr)
    {
        if (set.count(x + 1))
        {
            cnt += 1;
        }
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> arr0 = {1,2,3};
    cout << countElements(arr0) << '\n'; //2

    vector<int> arr1 = {1,1,3,3,5,5,7,7};
    cout << countElements(arr1) << '\n'; //0

    vector<int> arr2 = {1,3,2,3,5,0};
    cout << countElements(arr2) << '\n'; //3

    vector<int> arr3 = {1,1,2,2};
    cout << countElements(arr3) << '\n'; //2

    return 0;
}
