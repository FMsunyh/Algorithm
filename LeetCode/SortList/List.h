#pragma once
#include "Common.h"
class List
{
public:
	List();
	~List();

	ListNode* RemoveElements(ListNode* head, int val);

	bool TestRemoveElements(ListNode* head=nullptr, int val=0);
};

