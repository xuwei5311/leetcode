// leetcode construct binary tree from.cpp : 定义控制台应用程序的入口点。
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

int find(vector<int> &inorder,int x)
{
	for(int i=0;i<inorder.size();i++)
	{
		if(inorder[i] == x)
			return i;
	}
	return -1;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder,int s1 ,int e1,int s2,int e2) 
{
	if(e1 < s1)
		return NULL;
	TreeNode *root = new TreeNode(postorder[e2]);
	int mid = find(inorder,postorder[e2]);
	int leftnum = mid-s1;
	int rightnum = e1-mid;
	TreeNode *left = buildTree(inorder,postorder,s1,mid-1,s2,s2+leftnum-1);
	TreeNode *right = buildTree(inorder,postorder,mid+1,e1,s2+leftnum,e2-1);
	root->left = left;
	root->right = right;
	return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
{
	return buildTree(inorder,postorder,0,inorder.size()-1,0,inorder.size()-1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

