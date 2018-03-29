// leetcode populating next right pointers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <queue>
using namespace std;

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };
void connect(TreeLinkNode *root) 
{
	if(root == NULL)
		return;
	queue<TreeLinkNode*> Q;	
	Q.push(root);
	int currentLevelNum = 1;
	while(!Q.empty())
	{
		int nextLevelNum = 0;
		TreeLinkNode* p = Q.front();
		Q.pop();
		if(p->left)
		{
			Q.push(p->left);
			nextLevelNum++;
		}
		if(p->right)
		{
			Q.push(p->right);
			nextLevelNum++;
		}
		for(int i=1;i<currentLevelNum;i++)
		{	
			TreeLinkNode* q = Q.front();
			Q.pop();
			if(q->left)
			{
				Q.push(q->left);
				nextLevelNum++;
			}
			if(q->right)
			{
				Q.push(q->right);
				nextLevelNum++;
			}
			p->next = q;
			p = q;
		}
		p->next = NULL;
		currentLevelNum = nextLevelNum;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

