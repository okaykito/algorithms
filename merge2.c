#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];
	for (int i = 0; i < n1; i++) L[i] = arr[l + i];
	for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
	}
	while (i < n1) arr[k++] = L[i++];
	while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

int main() {
	srand(time(NULL));
	const int N = 100000;
	int arr[N];

	for (int i = 0; i < N; i++)
		arr[i] = rand() % 1000;

	for (int size = 5000; size <= N; size += 5000) {
		// Copy to temp array for fair timing
		int temp[size];
		for (int i = 0; i < size; i++)
			temp[i] = arr[i];

		clock_t start = clock();
		mergeSort(temp, 0, size - 1);
		clock_t end = clock();

		printf("Time to sort %d elements: %.6f seconds\n", size, (double)(end - start) / CLOCKS_PER_SEC);
	}

	return 0;
}
