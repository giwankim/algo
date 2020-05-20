#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
private:
    stack<pair<int, int>> s;

public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;
        while (!s.empty() && s.top().first <= price) {
            span += s.top().second;
            s.pop();
        }
        s.emplace(price, span);
        return span;
    }
};

int main(int argc, char const *argv[])
{
    {
        StockSpanner spanner = StockSpanner();
        cout << spanner.next(100) << endl;  // 1
        cout << spanner.next(80) << endl;   // 1
        cout << spanner.next(60) << endl;   // 1
        cout << spanner.next(70) << endl;   // 2
        cout << spanner.next(60) << endl;   // 1
        cout << spanner.next(75) << endl;   // 4
        cout << spanner.next(85) << endl;   // 6
    }
    return 0;
}
