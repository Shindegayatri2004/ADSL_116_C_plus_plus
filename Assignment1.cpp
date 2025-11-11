#include <iostream>
using namespace std;
int countZeros(int arr[], int n)
{
    int low = 0, high = n - 1;
    int firstZero = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == 0)
        {
            firstZero = mid;
            high = mid - 1;
        }
        else
        {

            low = mid + 1;
        }
    }
    if (firstZero == -1)
        return 0;

    return n - firstZero;
}

int main()
{

    int arr[100], n;
    cout << "enter no of elements:";
    cin >> n;
    cout << "enter array elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Number of zeros = " << countZeros(arr, n) << endl;

    return 0;
}
