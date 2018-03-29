// leetcode recovery binary search tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

void inordertraverse(TreeNode *root)
{
	if(!root)
		return;
	TreeNode* error1 = NULL;
	TreeNode* error2 = NULL;
	TreeNode* prenode = NULL;
	stack<TreeNode*> s;
	s.push(root);
	while(!s.empty())
	{
		TreeNode* p = s.top();
		while(p)
		{
			s.push(p->left);
			p = p->left;
		}
		s.pop();
		if(!s.empty())
		{
			TreeNode* q = s.top();
			if(!error1)  
			{
				if(prenode && prenode->val > q->val)
				{
					error1 = prenode;
					error2 = q;
				}
				prenode = q;
			}
			else
			{
				if(error2->val > q->val)
					error2 = q;
			}
			s.pop();
			s.push(q->right);
		}
	}
	int temp = error1->val;
	error1->val = error2->val;
	error2->val = temp;
}

void recoverTree(TreeNode *root) {
	inordertraverse(root);		       
}

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode* p1 = new TreeNode(1);
	TreeNode* p2 = new TreeNode(4);
	TreeNode* p3 = new TreeNode(3);
	TreeNode* p4 = new TreeNode(2);
	TreeNode* p5 = new TreeNode(5);
	p4->left = p2;
	p4->right = p5;
	p2->left = p1;
	p2->right = p3;
	recoverTree(p4);
	return 0;
}

