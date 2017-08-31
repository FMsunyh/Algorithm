#include "Common.h"

void MergeArray(int arr[], int first, int mid, int last, int temp[])
{
	int i = first;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= last)
	{
		if (arr[i] < arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}

	while (i <= mid)
	{
		temp[k++] = arr[i++];
	}

	while (j <= last)
	{
		temp[k++] = arr[j++];
	}

	for (int i = 0; i < k; ++i)
	{
		arr[first + i] = temp[i];
	}
}

void MergeSort(int arr[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		MergeSort(arr, first, mid, temp);
		MergeSort(arr, mid + 1, last, temp);
		MergeArray(arr, first, mid, last, temp);
	}
}

bool TestMergeSort(int arr[], int n)
{
	int *p = new int[n];
	if (p == nullptr)
	{
		return false;
	}

	MergeSort(arr, 0, n - 1, p);

	printArr(arr, n);

	delete p;

	return true;
}
