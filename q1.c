#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);
void swap(int *a, int *b);

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low;
    int j = high;

    while (i < j) {
        do {
            i++;
        } while (i <= high && a[i] <= pivot);
        do {
            j--;
        } while (a[j] > pivot);

        if (i < j)
            swap(&a[i], &a[j]);
    }
    swap(&a[low], &a[j]);
    return j;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    srand(time(NULL));
    const int n = 100000;
    int elements[n];

    // Fill the array with random elements
    for (int i = 0; i < n; i++) {
        elements[i] = rand() % 1000;
    }

    for (int size = 5000; size <= n; size += 2000) {
        int A[size];

        for (int i = 0; i < size; i++) {
            A[i] = elements[i]; // Copy to preserve fairness
        }

        clock_t start = clock();
        quicksort(A, 0, size - 1); // Fix high = size - 1
        clock_t end = clock();

        printf("Time to sort %d elements: %.6f seconds\n", size, (double)(end - start) / CLOCKS_PER_SEC);
    }
    return 0;
}
