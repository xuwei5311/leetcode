// leetcode partition list.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

ListNode *partition(ListNode *head, int x) {
	ListNode* lhead = NULL;
	ListNode* rhead = NULL;
	ListNode* ltail = NULL;
	ListNode* rtail = NULL;
	ListNode *p = head;
	while(p)
	{
		if(p->val < x)
		{
			if(!lhead)
			{
				lhead = p;
				ltail = p;
			}
			else
			{
				ltail->next = p;
				ltail = p;
			}
		}
		else
		{
			if(!rhead)
			{
				rhead = p;
				rtail = p;
			}
			else
			{
				rtail->next = p;
				rtail = p;
			}
		}
		p = p->next;
	}
	if(ltail)
		ltail->next = rhead;
	if(rtail)
		rtail->next = NULL;
	if(lhead)
		return lhead;
	else
		return rhead;
	return NULL;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(4);
	ListNode* p3 = new ListNode(3);
	ListNode* p4 = new ListNode(2);
	ListNode* p5 = new ListNode(5);
	ListNode* p6 = new ListNode(2);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	ListNode* head = partition(p1, 3);
	return 0;
}

