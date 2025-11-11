#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Sort the array so that duplicates are grouped together
    sort(arr.begin(), arr.end());

    set<vector<int>> distinct; // To store unique subsets

    int total = 1 << n; // Total subsets = 2^n
    for (int mask = 0; mask < total; ++mask) {
        vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(arr[i]);
            }
        }
        distinct.insert(subset); // Insert subset into set to avoid duplicates
    }

    cout << "\nDistinct subsets (" << distinct.size() << "):\n";
    for (const auto &s : distinct) {
        cout << "{ ";
        for (int x : s) {
            cout << x << " ";
        }
        cout << "}\n";
    }

    return 0;
}
