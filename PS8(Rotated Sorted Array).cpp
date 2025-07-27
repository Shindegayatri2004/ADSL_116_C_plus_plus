#include <iostream>
#include <vector>
using namespace std;

int searchInRotatedSortedArray(vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        // Check if left half is sorted
        if (arr[start] <= arr[mid]) {
            if (arr[start] <= target && target < arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (arr[mid] < target && target <= arr[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1; // Target not found
}

int main() {
    int n, target;

    // Get number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    // Input array
    cout << "Enter the elements of rotated sorted array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Input target
    cout << "Enter the target element to search: ";
    cin >> target;

    // Search
    int index = searchInRotatedSortedArray(arr, target);

    if (index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "Target not found in the array." << endl;

    return 0;
}
