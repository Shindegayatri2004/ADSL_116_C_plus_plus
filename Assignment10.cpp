#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(vector<int>& arr, int n, int sum) {
    // DP table: dp[i][j] = true if sum j can be made with first i elements
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // Base case: sum 0 is always possible (empty subset)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                // include or exclude the current element
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                // can't include current element
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main() {
    int n, sum;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the sum to check: ";
    cin >> sum;

    if (isSubsetSum(arr, n, sum)) {
        cout << "Yes, a subset with sum " << sum << " exists." << endl;
    } else {
        cout << "No, subset with sum " << sum << " does not exist." << endl;
    }

    return 0;
}
