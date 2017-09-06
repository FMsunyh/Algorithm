#include "Array.h"



Array::Array()
{
}


Array::~Array()
{
}

int Array::RemoveElement(vector<int>& nums, int val)
{
	////solution one:
	//if (nums.size() == 0)
	//	return 0;

	//vector<int>::iterator iter = nums.begin();

	//while (iter != nums.end())
	//{
	//	if (*iter == val)
	//	{
	//		iter = nums.erase(iter);
	//	}
	//	else
	//	{
	//		++iter;
	//	}
	//}

	//return nums.size();

	//solution two
	// The element doesn't delete readly. although we can solve the problem.
	// that will occur memory leak. if the element is pointer.
	int i = 0;
	int nCount = nums.size();
	while (i<nCount)
	{
		if (nums[i] == val)
		{
			nums[i] = nums[nCount - 1];
			--nCount;
		}
		else 
		{
			++i;
		}
	}

	return i;
}
