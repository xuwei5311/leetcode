// leetcode binary tree maximum path sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <map>
#include <vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

map<TreeNode*,int> g;
int Getg(TreeNode *root)
{
	if(root == NULL)
		return 0;
	if(g.find(root) != g.end())
		return g[root];
	g[root] = max(root->val,max(root->val + Getg(root->left),root->val + Getg(root->right)));
	return g[root];
}

int maxPathSum(TreeNode *root) 
{
	if(root == NULL)
		return -99999999;
	int a = maxPathSum(root->left);
	int b = maxPathSum(root->right);
	int c = root->val;
	int d = Getg(root->left);
	int e = Getg(root->right);
	if(d > 0)
		c += d;
	if(e > 0)
		c += e;
	return max(a,max(b,c));
}

int main()
{
	TreeNode *p1 = new TreeNode(9);
	TreeNode *p2 = new TreeNode(6);
	TreeNode *p3 = new TreeNode(-3);
	TreeNode *p4 = new TreeNode(-6);
	TreeNode *p5 = new TreeNode(2);
	TreeNode *p6 = new TreeNode(2);
	TreeNode *p7 = new TreeNode(-6);
	TreeNode *p8 = new TreeNode(-6);
	TreeNode *p9 = new TreeNode(-6);
	p1->left = p2;
	p1->right = p3;
	p3->left = p4;
	p3->right = p5;
	p5->left = p6;
	p6->left = p7;
	p6->right = p8;
	p7->left = p9;
	int a = maxPathSum(p1) ;
	return 0;
}

