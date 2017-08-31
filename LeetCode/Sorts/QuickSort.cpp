#include "Common.h"
#include "QuickSort.h"

int Partition(int arr[], int p, int r)
{
	int i = p, j = r;
	int x = arr[i];
	while (i < j)
	{
		while (i < j && arr[j] >= x)
			--j;

		if (i < j)
		{
			arr[i] = arr[j];
			++i;
		}

		while (i < j && arr[i] < x)
			++i;

		if (i < j)
		{
			arr[j] = arr[i];
			--j;
		}
	}

	arr[i] = x;
	return i;
}


void QuickSort(int arr[], int p, int r)
{
	if (p < r)
	{
		int i = Partition(arr, p, r);
		QuickSort(arr, p, i - 1);
		QuickSort(arr, i + 1, r);
	}
}

void TestQuickSort(int arr[], int n)
{
	//int a[] = { 2,3,5,8,1,4,9,6,7,0 };
	/*QuickSort(a, 0, 9);
	printArr(a, 10);*/

	QuickSort(arr, 0, n-1);
	printArr(arr, n);
}