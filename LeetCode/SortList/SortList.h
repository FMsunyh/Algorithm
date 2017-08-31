#pragma once
#include <iostream>
//Definition for singly - linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};


class SortList
{
public:
	ListNode* MergeSort(ListNode* head);

	ListNode* MergeTwoLists(ListNode* leftHead, ListNode* rightHead);

	bool TestSortList(ListNode* p);
};