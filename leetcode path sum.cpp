// leetcode path sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

bool hasPathSum(TreeNode *root, int sum) 
{
	if(root == NULL)
		return false;

	if(root->left == NULL && root->right == NULL)
	{
		if(root->val == sum)
			return true;
		else
			return false;
	}

	if(hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val))
		return true;
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

