#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to check if s1 can be transformed into s2
// Rules:
// 1. You can make lowercase letters uppercase.
// 2. You can delete lowercase letters.
// 3. Uppercase letters cannot be deleted or changed.
bool canTransform(const string &s1, const string &s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    dp[0][0] = true; // empty string to empty string is always possible

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (!dp[i][j]) continue;
            char a = s1[i];

            // Option 1: Delete lowercase letters
            if (islower(a)) {
                dp[i + 1][j] = true;
            }

            // Option 2: Match characters (convert lowercase to uppercase if needed)
            if (j < m && toupper(a) == s2[j]) {
                dp[i + 1][j + 1] = true;
            }
        }
    }

    return dp[n][m];
}

int main() {
    string s1, s2;
    cout << "Enter first string (s1): ";
    cin >> s1;
    cout << "Enter second string (s2 in uppercase): ";
    cin >> s2;

    if (canTransform(s1, s2))
        cout << "YES, it is possible to transform s1 into s2.\n";
    else
        cout << "NO, it is not possible to transform s1 into s2.\n";

    return 0;
}
