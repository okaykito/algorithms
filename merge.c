#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	// Create temp arrays
	int L[n1], R[n2];
	// Copy data to temp array
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];
// Merge the temp arrays
i = 0;
j = 0;
k = l;
while (i < n1 && j < n2)
{
	if (L[i] <= R[j])
	{
		arr[k] = L[i];
		i++;
	}
	else
	{
		arr[k] = R[j];
		j++;
	}
	k++;
}
// Copy the remaining elements of L[]
while (i < n1)
{
	arr[k] = L[i];
	i++;
	k++;
}
// Copy the remaining elements of R[]
while (j < n2)
{
	arr[k] = R[j];
	j++;
	k++;
}
}
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
	// Finding mid element
	int m = l+(r-l)/2;
	// Recursively sorting both the halves
	mergeSort(arr, l, m);
	mergeSort(arr, m+1, r);
	merge(arr, l, m, r);
	}
}
void main()
{
	srand(time(NULL));
	int arr[100000],n=100000,i,size;
	int elements[n];
	for(i=0;i<n;i++)
		elements[i]=rand()%1000;
	for(size=5000;size<n;size+=5000)
	{
		arr[size];
		for(i=0;i<n;i++)
		{
			arr[i]=elements[i];
		}
		clock_t start=clock();
		mergeSort(arr, 0,size);
		clock_t end=clock();
		printf("Total time taken to sort %d elements  is %lf\n",size,((double)(end-start)/CLOCKS_PER_SEC));
	}
}

