// leetcode remove duplicates from sorted ii.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

ListNode *deleteDuplicates(ListNode *head) {
	ListNode* h = new ListNode(0);
	h->next = head;
	ListNode* pre = h;
	ListNode* p = head;
	while(p)
	{
		if(p->next && p->next->val == p->val)
		{
			int val = p->val;
			while(p && p->val == val)
			{
				pre->next = p->next;
				p = p->next;
			}
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
	return h->next;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode* p = new ListNode(1);
	ListNode* q = new ListNode(1);
	p->next = q;
	deleteDuplicates(p);
	return 0;
}

