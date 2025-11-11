#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Structure to store weight and value of an item
struct Item {
    int w; // weight
    int v; // value
};

// Node for Branch and Bound tree
struct Node {
    int level;   // index of the last considered item
    int profit;  // current profit
    int weight;  // current weight
    double bound; // upper bound on profit from this node
};

// Comparator for priority queue (max-heap by bound)
struct CompareBound {
    bool operator()(const Node &a, const Node &b) const {
        return a.bound < b.bound; // max-heap
    }
};

// Function to calculate upper bound (fractional knapsack idea)
double getBound(const Node &u, int n, int W, const vector<Item> &items) {
    if (u.weight >= W)
        return 0.0;

    double profitBound = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;

    // take items while they fit completely
    while (j < n && totalWeight + items[j].w <= W) {
        totalWeight += items[j].w;
        profitBound += items[j].v;
        j++;
    }

    // take fraction of next item (if any)
    if (j < n) {
        profitBound += (W - totalWeight) * (double)items[j].v / items[j].w;
    }

    return profitBound;
}

// Function to solve 0/1 Knapsack using Branch and Bound
int knapSackBB(int W, vector<Item> items) {
    int n = items.size();

    // Sort items by decreasing value/weight ratio
    sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
        return (double)a.v / a.w > (double)b.v / b.w;
    });

    priority_queue<Node, vector<Node>, CompareBound> pq;
    Node u, v;

    // Start with dummy node at level -1 (no items considered yet)
    u.level = -1;
    u.profit = 0;
    u.weight = 0;
    u.bound = getBound(u, n, W, items);
    pq.push(u);

    int maxProfit = 0;

    while (!pq.empty()) {
        u = pq.top();
        pq.pop();

        // Skip if bound is not better than current best
        if (u.bound <= maxProfit)
            continue;

        v.level = u.level + 1;

        // Option 1: Take next item
        v.weight = u.weight + items[v.level].w;
        v.profit = u.profit + items[v.level].v;

        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = getBound(v, n, W, items);
        if (v.bound > maxProfit)
            pq.push(v);

        // Option 2: Do not take next item
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = getBound(v, n, W, items);
        if (v.bound > maxProfit)
            pq.push(v);
    }

    return maxProfit;
}

int main() {
    int n, W;
    cout << "Enter number of items and capacity W: ";
    cin >> n >> W;

    vector<Item> items(n);
    cout << "Enter weight and value for each item:\n";
    for (int i = 0; i < n; ++i) {
        cin >> items[i].w >> items[i].v;
    }

    int best = knapSackBB(W, items);
    cout << "\nMaximum profit (Branch & Bound) = " << best << endl;

    return 0;
}
