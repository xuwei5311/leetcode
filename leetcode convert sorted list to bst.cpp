// leetcode convert sorted list to bst.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

 //ƽ����
TreeNode *sortedListToBST1(vector<int>& data,int s,int e)
{
	if(e < s)
		return NULL;
	TreeNode* left = sortedListToBST1(data,s,(s+e+1)/2-1); //ƽ������Ψһ��Ϊ����������һ�£�������s+e+1������s+e
	TreeNode* right = sortedListToBST1(data,(s+e+1)/2+1,e);
	TreeNode* root = new TreeNode(data[(s+e+1)/2]);
	root->left = left;
	root->right = right;
	return root;
}

TreeNode *sortedListToBST(ListNode *head) 
{
	vector<int> data;
	ListNode* p = head;
	while(p)
	{
		data.push_back(p->val);
		p = p->next;
	}
	return sortedListToBST1(data,0,data.size()-1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode* p = new ListNode(1);
	ListNode* q = new ListNode(3);
	p->next = q;
	sortedListToBST(p);
	return 0;
}

