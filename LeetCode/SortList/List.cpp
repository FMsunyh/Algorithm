#include "List.h"


List::List()
{
}


List::~List()
{
}

ListNode* List::RemoveElements(ListNode* head, int val)
{
	if (head == nullptr)
		return head;

	ListNode* result = new ListNode(0);
	result->next = nullptr;

	ListNode* pCursor = head;
	ListNode* pCur = result;
	ListNode *tmp = nullptr;
	while (pCursor!=nullptr && pCursor->val == val)
	{
		tmp = pCursor->next;
		delete pCursor;
		pCursor = tmp;
	}

	while (pCursor!=nullptr)
	{
		if (pCursor->val == val)
		{
			tmp = pCursor;
			//pCur->next = pCursor->next;
			pCursor = pCursor->next;
			delete tmp;
			tmp = nullptr;
		}
		else
		{
			pCur->next = pCursor;
			pCur = pCur->next;
			pCursor = pCursor->next;
		}

		pCur->next = nullptr;
	}

	ListNode* p = result->next;
	delete result;
	result = nullptr;
	return p;

	/*if (head == nullptr)
		return head;
	while (head != nullptr && head->val == val)
	{
		head = head->next;
	}

	if (head == nullptr)
		return nullptr;

	ListNode* prev = head;
	ListNode* node = prev->next;

	while (node != nullptr)
	{
		if (node->val == val)
		{
			prev->next = node->next;
		}
		else
		{
			prev = node;
		}

		node = node->next;
	}

	return head;*/
}

bool List::TestRemoveElements(ListNode* head/*=nullptr*/, int val/*=0*/)
{
	ListNode* pl1 = new ListNode(3);
	ListNode* pl2 = new ListNode(4);
	ListNode* pl3 = new ListNode(1);
	ListNode* pl4 = new ListNode(4);
	pl1->next = pl2;
	pl2->next = pl3;
	pl3->next = pl4;
	//head->next = pl1;
	ListNode* pSortlist = nullptr;
	pSortlist = RemoveElements(pl1,4);

	return pSortlist != nullptr;
}
