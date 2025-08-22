#include <iostream>
#include <vector>
#include <cmath>      // for ceil
#include <algorithm>  // for max_element
using namespace std;

// Function to check: with given capacity C, how many days are needed?
int daysRequired(vector<int>& tasks, int C) {
    int days = 0;
    for (int work : tasks) {
        // each task may take multiple days if work > C
        days += ceil((double)work / C);
    }
    return days;
}

// Function to find minimum daily capacity
int minimumCapacity(vector<int>& tasks, int D) {
    int left = 1;                  
    int right = *max_element(tasks.begin(), tasks.end()); // max task size
    int answer = right;

    while (left <= right) {
        int mid = (left + right) / 2; // try this capacity
        int requiredDays = daysRequired(tasks, mid);

        if (requiredDays <= D) {
            // This capacity works → try smaller
            answer = mid;
            right = mid - 1;
        } else {
            // Too small → increase capacity
            left = mid + 1;
        }
    }
    return answer;
}

int main() {
    int N, D;
    cout << "Enter number of tasks: ";
    cin >> N;

    vector<int> tasks(N);
    cout << "Enter work for each task: ";
    for (int i = 0; i < N; i++) cin >> tasks[i];

    cout << "Enter maximum days allowed: ";
    cin >> D;

    int result = minimumCapacity(tasks, D);
    cout << "Minimum daily capacity required = " << result << " units/day" << endl;
    return 0;
}
