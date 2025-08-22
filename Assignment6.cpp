#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices) {
    int buy_price = prices[0]; // Initial buy price (first day)
    int profit = 0;            // Maximum profit

    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < buy_price) {
            // Found a cheaper day to buy
            buy_price = prices[i];
        } else {
            // Calculate profit if selling today
            int current_profit = prices[i] - buy_price;
            profit = max(current_profit, profit);
        }
    }
    return profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << maxProfit(prices) << endl;
    return 0;
}
