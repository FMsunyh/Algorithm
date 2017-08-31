#include "QuickSort.h"
#include "MergeSort.h"

int main()
{
	int arr[] = { 2,3,5,8,1,4,9,6,7,0 };
	TestQuickSort(arr, 10);

	int arr1[] = { 2,3,5,8,1,4,9,6,7,0 };
	TestMergeSort(arr1, 10);
}