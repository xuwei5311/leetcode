// leetcode spiral matrix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix) {
	vector<int> res;
	int m = matrix.size();
	if(m == 0)
		return res;
	int n = matrix[0].size();
	if(n == 0)
		return res;
	int lt_i = 0;
	int lt_j = 0;
	int rb_i = m-1;
	int rb_j = n-1;
	while(lt_i <= rb_i && lt_j <= rb_j)
	{
		//每次访问外围一圈
		for(int j=lt_j;j<=rb_j;j++)
			res.push_back(matrix[lt_i][j]);
		for(int i=lt_i+1;i<=rb_i-1;i++)
			res.push_back(matrix[i][rb_j]);
		if(lt_i != rb_i)
		{
			for(int j=rb_j;j>=lt_j;j--)
				res.push_back(matrix[rb_i][j]);
		}
		if(lt_j != rb_j)
		{
			for(int i=rb_i-1;i>=lt_i+1;i--)
				res.push_back(matrix[i][lt_j]);
		}
		lt_i++;
		lt_j++;
		rb_i--;
		rb_j--;
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int data[][3] = {1,2,3,
	4,5,6,
	7,8,9};
	vector<vector<int> > matrix;
	for(int i=0;i<3;i++)
	{
		vector<int> tmp;
		for(int j=0;j<3;j++)
			tmp.push_back(data[i][j]);
		matrix.push_back(tmp);
	}
	spiralOrder(matrix);
	return 0;
}

