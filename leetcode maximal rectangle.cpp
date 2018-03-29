// leetcode maximal rectangle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <stack>
using namespace std;

//解法1
const int MAXNUM = 100;
int f[MAXNUM] = {0};
int g[MAXNUM][MAXNUM][MAXNUM] = {0};
int maximalRectangle1(vector<vector<char> > &matrix) {
	for(int i=0;i<MAXNUM;i++)
		f[i] = 0;
	for(int i=0;i<MAXNUM;i++)
		for(int j=0;j<MAXNUM;j++)
			for(int k=0;k<MAXNUM;k++)
				g[i][j][k] = 0;
	int m = matrix.size();
	if(m == 0)
		return 0;
	int n = matrix[0].size();
	if(n == 0)
		return 0;
	for(int k=0;k<n;k++)
	{
		int maxg = 0;
		for(int i=0;i<m;i++)
		{
			for(int j=i;j<m;j++)
			{
				if(matrix[j][k] == '1')
				{
					if(k==0)
						g[i][j][k] = j-i+1;
					else
						g[i][j][k] = g[i][j][k-1]+j-i+1;
					maxg = max(maxg,g[i][j][k]);
				}
				else
					break;
			}
		}
		if(k==0)
			f[k] = maxg;
		else
			f[k] = max(maxg,f[k-1]);
	}
	return f[n-1];
}

//解法2
struct rect
{
	int w;
	int h;
};
int largestRectangleArea(vector<rect> rects)
{
	stack<rect> s;
	int M = 0;
	for(int i=0;i<rects.size();i++)
	{
		int w = 0;
		while(!s.empty() && rects[i].h <= s.top().h)
		{
			w += s.top().w;
			if(rects[i].h != s.top().h)
				M = max(M,w * s.top().h);
			s.pop();   //由于rects中最后一个矩形是0，最后单调栈中矩形高度都是0
		}
		rect temp = {w+rects[i].w,rects[i].h};
		s.push(temp);
	}
	return M;
}

int maximalRectangle(vector<vector<char> > &matrix)
{
	int m = matrix.size();
	if(m == 0)
		return 0;
	int n = matrix[0].size();
	if(n == 0)
		return 0;
	vector<rect> rects;
	for(int j=0;j<n+1;j++)  //最后加一个高度为0的矩形，方便处理
	{
		rect r = {1,0};
		rects.push_back(r);
	}
	int res = 0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(matrix[i][j] == '1')
				rects[j].h += 1;
			else
				rects[j].h = 0;
		}
		res = max(res,largestRectangleArea(rects));
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char data[][5] = {'0','1','1','0','1',
		'1','1','0','1','0',
		'0','1','1','1','0',
		'1','1','1','1','0',
		'1','1','1','1','1',
		'0','0','0','0','0',
	};
	vector<vector<char> > matrix;
	for(int i=0;i<6;i++)
	{
		vector<char> temp;
		for(int j=0;j<5;j++)
		{
			temp.push_back(data[i][j]);
		}
		matrix.push_back(temp);
	}
	int area = maximalRectangle(matrix);
	return 0;
}

