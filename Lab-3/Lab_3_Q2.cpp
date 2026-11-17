#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxProfit(vector<int>& price) {
    if (price.empty()) return 0;
    int minPrice = price[0], profit = 0;
    for (int i = 1; i < (int)price.size(); i++) {
        profit = max(profit, price[i] - minPrice);
        minPrice = min(minPrice, price[i]);
    }
    return profit;
}
int main() {
    vector<int> price = {7, 1, 5, 3, 6, 4};
    cout << "Maximum profit = " << maxProfit(price);
    return 0;
}
