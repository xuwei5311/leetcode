// leetcode rotate images.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

void rotate(vector<vector<int> > &matrix) {
	vector<vector<int> > matrixcp(matrix);
	int n = matrix.size();
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			matrix[i][j] = matrixcp[n-1-j][i];
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

