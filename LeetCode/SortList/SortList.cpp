#include "SortList.h"

ListNode* SortList::MergeSort(ListNode* pHead)
{
	if (pHead == nullptr || pHead->next == nullptr)
		return pHead;

	ListNode* pQuickPoint = pHead->next;
	ListNode* pSlowPoint = pHead;
	while (pQuickPoint != nullptr && pQuickPoint->next != nullptr)
	{
		pQuickPoint = pQuickPoint->next->next;
		pSlowPoint = pSlowPoint->next;
	} 
	ListNode* pMiddle = pSlowPoint->next;
	pSlowPoint->next = nullptr;

	ListNode* l1 = MergeSort(pHead);
	ListNode* l2 = MergeSort(pMiddle);
	return MergeTwoLists(l1, l2);
}

ListNode* SortList::MergeTwoLists(ListNode* leftHead, ListNode* rightHead)
{
	if (nullptr == leftHead && nullptr == rightHead)
		return nullptr;

	ListNode* pList = new ListNode(0);
	ListNode* newhead = pList;
	while (leftHead != nullptr && rightHead != nullptr)
	{
		if (leftHead->val < rightHead->val)
		{
			pList->next = leftHead;
			pList = pList->next;
			leftHead = leftHead->next;
		}
		else
		{
			pList->next = rightHead;
			pList = pList->next;
			rightHead = rightHead->next;
		}
	}

	if (leftHead != nullptr)
	{
		pList->next = leftHead;
	}
	else if (rightHead != nullptr)
	{
		pList->next = rightHead;
	}

	return newhead->next;
}

bool SortList::TestSortList(ListNode* p)
{
	ListNode* pl1 = new ListNode(5);
	ListNode* pl2 = new ListNode(1);
	ListNode* pl3 = new ListNode(2);
	ListNode* pl4 = new ListNode(4);
	pl1->next = pl2;
	pl2->next = pl3;
	pl3->next = pl4;
	SortList* pS = new SortList();
	ListNode* pSortlist = nullptr;
	if (nullptr != pS)
	{
		pSortlist = pS->MergeSort(pl1);
	}

	return pSortlist != nullptr;
}
