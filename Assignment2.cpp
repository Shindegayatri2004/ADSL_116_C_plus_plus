#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)

{
    int temp[100];
    int i = left, j = mid + 1, k = left;


    while (i <= mid && j <= right) 
    {
        if (arr[i] != 0 && arr[j] != 0) {
            temp[k++] = arr[i++];
        } else if (arr[i] == 0 && arr[j] != 0) {
            temp[k++] = arr[j++];
        } else if (arr[i] != 0 && arr[j] == 0) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[i++]; 
        }
    }

    
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    
    for (int p = left; p <= right; p++) {
        arr[p] = temp[p];
    }
}

void mergeSortZeroPush(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSortZeroPush(arr, left, mid);
        mergeSortZeroPush(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int nums[100], size;

    cout << "Enter size of array: ";
    cin >> size;

    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }

    mergeSortZeroPush(nums, 0, size - 1);

    
    int nonZeroCount = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] != 0) nums[nonZeroCount++] = nums[i];
    }
    while (nonZeroCount < size) {
        nums[nonZeroCount++] = 0;
    }

    cout << "\nAfter moving zeros using merge logic: ";
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
