// leetcode reverse linked list ii.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

ListNode *reverseBetween(ListNode *head, int m, int n) {
	if(head == NULL)
		return NULL;
	int length = 0;
	ListNode *point = head;
	while(point)
	{
		length++;
		point = point->next;
	}
	if(m<=0 || m>length || n<=0 || n>length || m == n)
		return head;
	ListNode *p1 = NULL;   
	ListNode *p = head;
	for(int i=0;i<m-1;i++)
	{
		p1 = p;
		p = p->next;
	}
	ListNode *start = p;
	ListNode *q = p->next;
	for(int i=0;i<n-m;i++)
	{
		ListNode * r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	if(p1 != NULL)
	{
		p1->next = p;
	}
	start->next = q;
	if(p1 != NULL)
		return head;
	else
		return p;
	return NULL;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode *p = new ListNode(1);
	ListNode *q = new ListNode(2);
	ListNode *r = new ListNode(3);
	p->next = q;
	q->next = r;
	reverseBetween(p, 1, 3);
	return 0;
}

