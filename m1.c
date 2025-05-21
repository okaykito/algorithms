#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int array[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int leftArray[leftSize], rightArray[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < rightSize; j++)
        rightArray[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Merge the two subarrays
    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j])
            array[k++] = leftArray[i++];
        else
            array[k++] = rightArray[j++];
    }

    // Copy remaining elements of leftArray
    while (i < leftSize)
        array[k++] = leftArray[i++];

    // Copy remaining elements of rightArray
    while (j < rightSize)
        array[k++] = rightArray[j++];
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int main() {
    srand(time(NULL));
    const int TOTAL_ELEMENTS = 100000;
    int mainArray[TOTAL_ELEMENTS];

    // Fill array with random numbers between 0 and 999
    for (int i = 0; i < TOTAL_ELEMENTS; i++)
        mainArray[i] = rand() % 1000;

    for (int currentSize = 5000; currentSize <= TOTAL_ELEMENTS; currentSize += 5000) {
        int testArray[currentSize];
        for (int i = 0; i < currentSize; i++)
            testArray[i] = mainArray[i];

        clock_t start = clock();
        mergeSort(testArray, 0, currentSize - 1);
        clock_t end = clock();

        double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Time to sort %d elements: %.6f seconds\n", currentSize, timeTaken);
    }

    return 0;
}
