#pragma once
#include <iostream>
#include "Common.h"


class SortList
{
public:
	ListNode* MergeSort(ListNode* head);

	ListNode* MergeTwoLists(ListNode* leftHead, ListNode* rightHead);

	ListNode* InsertionSortList(ListNode* head);

	bool TestMergeSortList(ListNode* p);

	bool SortList::TestInsertionSortList(ListNode* p);
};