#pragma once
#include "SortList.h"
#include "List.h"

int main()
{
	SortList* pS = new SortList();
	//pS->TestMergeSortList(new ListNode(0));
	pS->TestInsertionSortList(new ListNode(0));

	List* pL = new List();
	pL->TestRemoveElements();
}
