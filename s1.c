#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    srand(time(NULL));
    const int MAX = 30000;
    int data[MAX];

    // Fill the array with random values
    for (int i = 0; i < MAX; i++) {
        data[i] = rand() % 1000;
    }

    // Run and time selection sort for increasing input sizes
    for (int size = 5000; size <= MAX; size += 2000) {
        int arr[size];
        for (int i = 0; i < size; i++) {
            arr[i] = data[i];
        }

        clock_t start = clock();
        selectionSort(arr, size);
        clock_t end = clock();

        double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Time taken to sort %d elements: %.6f seconds\n", size, timeTaken);
    }

    return 0;
}
