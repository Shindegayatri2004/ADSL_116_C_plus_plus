#include <iostream>
#include <vector>
using namespace std;

int countWays(vector<int>& coins, int sum) {
    vector<int> dp(sum + 1, 0);
    dp[0] = 1; // base case

    for (int coin : coins) {
        for (int i = coin; i <= sum; i++) {
            dp[i] += dp[i - coin];
        }
    }
    return dp[sum];
}

int main() {
    int n, sum;

    // Input size of array
    cout << "Enter number of coin types: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Input target sum
    cout << "Enter the sum to make: ";
    cin >> sum;

    // Output result
    cout << "Number of ways = " << countWays(coins, sum) << endl;

    return 0;
}
