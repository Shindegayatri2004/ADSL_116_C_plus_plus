#include <iostream>
using namespace std;

int countTrailingZeros(int n) 
{
    int res = 0;
    int powof5 = 5;

    while (n >= powof5) {
        res += (n / powof5);
        powof5 *= 5;
    }

    return res;
}


int smallestNumberWithAtLeastNTrailingZeros(int N) 
{
    int low = 0, high = 5 * N;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int zeros = countTrailingZeros(mid);

        if (zeros >= N) {
            result = mid;      // Mid might be the answer, look for smaller
            high = mid - 1;
        } else {
            low = mid + 1;     // Need more zeros
        }
    }
    return result;
}

// Driver code
int main() {
    int N;
    cout << "Enter N (minimum trailing zeros): ";
    cin >> N;

    int result = smallestNumberWithAtLeastNTrailingZeros(N);
    cout << "Smallest number whose factorial has at least " << N << " trailing zeros is: " << result << endl;

    return 0;
}


