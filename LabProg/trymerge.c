#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l,m,r);
    }
}

void merge(int arr[], int l, int m, int r) {
    int left = m - l + 1;
    int right = r - m;

    int LeftArr[left], RightArr[right]

    for(int i = 0; i < left; i++) {
        leftArr[i] = array[l + i];
    }

    for(int j = 0; j < right; j++) {
        RightArr[i] = array[m + 1 + j]
    }

    int i = 0; j = 0, k = l;

    while (i < left && j < right) {
        if(leftArr[i] <= RightArr[j])
            arr[k++] = leftArr[i++];
        else 
            arr[k++] = RightArr[j++];
    }

    while (i < left)
        arr[k++] = leftArr[i++];

    while (i < right)
        arr[k++] = rightArr[j++];
}

int main() {
    srand(time(NULL));
    const int TOTAL_ELEMENTS = 10000;
    int arr[TOTAL_ELEMENTS];

    for(int i = 0; i < TOTAL_ELEMENTS; i++) {
        arr[i] = rand() % 1000;
    }

    for(int size = 5000; size <= TOTAL_ELEMENTS; size += 5000) {
        int temp[size];

        for(int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }

        clock_t start = clock();
        mergeSort(temp, 0, size - 1);
        clock_t end = clock();

        printf("Time taken to sort %d elements in %.6f seconds\n",size,(double)(end - start) / CLOCKS_PER_SEC)
    }
    return 0;
}