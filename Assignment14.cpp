#include <iostream>
#include <vector>
#include <cmath>   // for abs()
using namespace std;

// Check if placing a queen at (row, col) is safe
bool isSafe(const vector<int>& colByRow, int row, int col) {
    for (int r = 0; r < row; ++r) {
        int c = colByRow[r];
        if (c == col) return false;                 // same column
        if (abs(c - col) == abs(r - row)) return false; // same diagonal
    }
    return true;
}

// Recursive function to place queens
void solveNQueens(int n, int row, vector<int>& colByRow, vector<vector<int>>& solutions) {
    if (row == n) {
        solutions.push_back(colByRow); // found valid arrangement
        return;
    }

    for (int c = 0; c < n; ++c) {
        if (isSafe(colByRow, row, c)) {
            colByRow[row] = c;               // place queen
            solveNQueens(n, row + 1, colByRow, solutions); // move to next row
            // Backtrack automatically (value overwritten later)
        }
    }
}

int main() {
    int n;
    cout << "Enter N for N-Queens (e.g., 4 or 8): ";
    cin >> n;

    vector<int> colByRow(n, -1);
    vector<vector<int>> solutions;

    solveNQueens(n, 0, colByRow, solutions);

    cout << "\nTotal solutions: " << solutions.size() << "\n\n";

    // Print up to first 5 solutions
    for (size_t k = 0; k < solutions.size(); ++k) {
        cout << "Solution " << k + 1 << ":\n";
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c)
                cout << (solutions[k][r] == c ? 'Q' : '.');
            cout << '\n';
        }
        cout << '\n';
        if (k >= 4) break; // show at most 5 solutions
    }

    return 0;
}
