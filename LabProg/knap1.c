#include <stdio.h>

int weights[20], profits[20], numItems;

// Returns maximum of two values
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive 0/1 Knapsack
int knapsack(int index, int capacity) {
    if (index == numItems) {
        return (weights[index] > capacity) ? 0 : profits[index];
    }

    // If current item can't be included, skip it
    if (weights[index] > capacity)
        return knapsack(index + 1, capacity);

    // Max of including or not including current item
    return max(
        knapsack(index + 1, capacity),                          // Not taking the item
        knapsack(index + 1, capacity - weights[index]) + profits[index]  // Taking the item
    );
}

int main() {
    int capacity;

    printf("Enter number of items: ");
    scanf("%d", &numItems);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Enter profit and weight of each item:\n");
    for (int i = 0; i < numItems; i++) {
        scanf("%d %d", &profits[i], &weights[i]);
    }

    int maxProfit = knapsack(0, capacity);
    printf("Maximum Profit: %d\n", maxProfit);

    return 0;
}
