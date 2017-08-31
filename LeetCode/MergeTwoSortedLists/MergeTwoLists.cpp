
//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		if (nullptr == l1 && nullptr == l2)
			return nullptr;

		ListNode* pList = new ListNode(0);
		ListNode* newhead = pList;
		while (l1 != nullptr && l2 != nullptr)
		{
			if (l1->val < l2->val)
			{
				pList->next = l1;
				pList = pList->next;
				l1 = l1->next;
			}
			else
			{
				pList->next = l2;
				pList = pList->next;
				l2 = l2->next;
			}
		}
		  
		if (l1 != nullptr)
		{
			pList->next = l1;
		}
		else if (l2 != nullptr)
		{
			pList->next = l2;
		}

		return newhead->next;
	}
};

int main()
{
	ListNode* pl1 = new ListNode(5);
	ListNode* pl2 = new ListNode(1);
	ListNode* pl3 = new ListNode(2);
	ListNode* pl4 = new ListNode(4);
	pl2->next = pl3;
	pl3->next = pl4;
	Solution* pS = new Solution();
	if (nullptr != pS)
	{
		pS->mergeTwoLists(pl1, pl2);
	}

}
