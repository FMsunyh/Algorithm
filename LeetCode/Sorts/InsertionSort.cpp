#include "Common.h"
#include "InsertionSort.h"

void InsertionSort(int arr[], int n)
{
	for (int i = 1; i < n; ++i)
	{
		for (int j = i; j > 0; --j)
		{
			if (arr[j] < arr[j - 1])
			{
				break;
			}
			else
			{
				swap(arr[j], arr[j - 1]);
			}
		}
	}
}

void InsertionSort1(int arr[], int n)
{
	for (int i = 1; i < n; ++i)
	{		int j = i;		int tmp = arr[i];		while (j > 0)		{			if (tmp > arr[j-1])			{				arr[j] = arr[j - 1];				--j;			}			else			{				break;			}		}		if(j != i)			arr[j] = tmp;	}
}


void swap(int& left, int& right)
{
	int tmp;
	tmp = left;
	left = right;
	right = tmp;
}


bool TestInsertionSort(int arr[], int n)
{
	int const  nCount = 10;
	//int arr[nCount] = { 2,3,5,4,7,8,9,1,6,0 };
	//InsertionSort(arr, nCount);
	InsertionSort1(arr, nCount);
	printArr(arr, nCount);

	return true;
}