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


ListNode* SortList::InsertionSortList(ListNode* head)
{
	/*if (nullptr == head || head->next == nullptr)
		return head;

	ListNode* pCur = head->next;

	while (pCur)
	{
		ListNode* pCursor = head;

		while (pCursor != pCur)
		{
			if (pCur->val > pCursor->val)
			{
				pCursor = pCursor->next;
			}
			else
			{
				int tmp = pCursor->val;
				pCursor->val = pCur->val;
				pCur->val = tmp;
				break;
			}
		}

		pCur = pCur->next;
	}

	return head;*/


	if (nullptr == head || head->next == nullptr)
		return head;

	ListNode* pPerCur = head->next;
	ListNode* pCur = pPerCur->next;

	while (pCur)
	{
		ListNode* pPerCursor = head;
		ListNode* pCursor = head->next;

		while (pCursor != pCur)
		{
			if (pCur->val > pCursor->val)
			{
				pPerCursor = pCursor;
				pCursor = pCursor->next;
			}
			else
			{
				pPerCur->next = pCur->next;
				pPerCursor->next = pCur;				
				pCur->next = pCursor;

				pCur = pPerCur->next;
				break;
			}
		}

		if (pCursor == pCur)
		{
			pPerCur = pCur;
			pCur = pCur->next;
		}
	}

	return head->next;
}



bool SortList::TestMergeSortList(ListNode* p)
{
	ListNode* pl1 = new ListNode(5);
	ListNode* pl2 = new ListNode(1);
	ListNode* pl3 = new ListNode(2);
	ListNode* pl4 = new ListNode(4);
	pl1->next = pl2;
	pl2->next = pl3;
	pl3->next = pl4;
	p->next = pl1;
	SortList* pS = new SortList();
	ListNode* pSortlist = nullptr;
	if (nullptr != pS)
	{
		pSortlist = pS->MergeSort(p);
	}

	return pSortlist != nullptr;
}


bool SortList::TestInsertionSortList(ListNode* p)
{
	ListNode* pl1 = new ListNode(3);
	ListNode* pl2 = new ListNode(4);
	ListNode* pl3 = new ListNode(1);
	ListNode* pl4 = new ListNode(4);
	pl1->next = pl2;
	pl2->next = pl3;
	//pl3->next = pl4;
	p->next = pl1;
	SortList* pS = new SortList();
	ListNode* pSortlist = nullptr;
	if (nullptr != pS)
	{
		pSortlist = pS->InsertionSortList(p);
	}

	return pSortlist != nullptr;
}
