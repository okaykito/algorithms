#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j < high; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}

void quicksort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

int main() {
	srand(time(NULL));
	const int N = 100000;
	int base[N];

	// Pre-fill base array with random values
	for (int i = 0; i < N; i++)
		base[i] = rand() % 1000;

	for (int size = 5000; size <= N; size += 2000) {
		int arr[size];
		for (int i = 0; i < size; i++)
			arr[i] = base[i];

		clock_t start = clock();
		quicksort(arr, 0, size - 1);
		clock_t end = clock();

		printf("Time to sort %d elements: %.6f seconds\n", size, (double)(end - start) / CLOCKS_PER_SEC);
	}

	return 0;
}
