// leetcode convert sorted list to bst.cpp : 定义控制台应用程序的入口点。
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

 //平衡树
TreeNode *sortedListToBST1(vector<int>& data,int s,int e)
{
	if(e < s)
		return NULL;
	TreeNode* left = sortedListToBST1(data,s,(s+e+1)/2-1); //平衡树不唯一，为了与判题结果一致，所以用s+e+1而不是s+e
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

