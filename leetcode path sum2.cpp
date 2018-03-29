// leetcode path sum2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

void pathSum1(TreeNode *root, int sum,vector<int>& path,vector<vector<int> >& result) 
{
	if(root == NULL)
		return;
	if(root->left == NULL && root->right == NULL)
	{
		if(root->val == sum)
		{
			path.push_back(root->val);
			result.push_back(path);
			path.pop_back();
		}
		return;
	}

	path.push_back(root->val);
	pathSum1(root->left, sum-root->val,path,result);
	pathSum1(root->right, sum-root->val,path,result);
	path.pop_back();
}

vector<vector<int> > pathSum(TreeNode *root, int sum) 
{
	vector<int> path;
	vector<vector<int> > result;
	pathSum1(root, sum, path, result);	
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

