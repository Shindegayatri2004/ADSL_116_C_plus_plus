#include <iostream>
using namespace std;

void pushZerosToEnd(int arr[], int n) {
    int j = 0; 

   
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[j++] = arr[i]; 
        }
    }

    while (j < n) {
        arr[j++] = 0;
    }
}

int main() {
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    pushZerosToEnd(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

