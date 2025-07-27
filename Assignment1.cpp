#include <iostream>
using namespace std;

int countzeros(int arr[], int n) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low +high) / 2;

        if (arr[mid] == 1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    
    return n - low;
}

int main() {
    int a[100], n;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements (1's followed by 0's): ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int zeroCount = countzeros(a, n);
    cout << "Number of 0's = " << zeroCount << endl;

    return 0;
}
