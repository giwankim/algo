#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int profit = 0;
    for (int i = 0; i + 1 < prices.size(); ++i) {
        if (prices[i] < prices[i+1]) {
            profit += prices[i+1] - prices[i];
        }
    }
    return profit;
}

int main(int argc, char const *argv[])
{
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << '\n';  // 7

    vector<int> prices2 = {1,2,3,4,5};
    assert(maxProfit(prices2) == 4);
    cout << maxProfit(prices2) << '\n';  // 4

    vector<int> prices3 = {7,6,4,3,1};
    cout << maxProfit(prices3) << '\n';  // 0
    return 0;
}
