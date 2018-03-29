// leetcode search a 2d matrix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

/*首先选取右上角数字，如果该数字等于要查找的数字，查找过程结束；如果该数字大于要查找的数字，
去掉此数字所在列；如果该数字小于要查找的数字，则去掉该数字所在行。重复上述过程直到找到要查
找的数字，或者查找范围为空。*/
bool searchMatrix(vector<vector<int> > &matrix, int target) {
	int m = matrix.size();
	if(m == 0)
		return false;
	int n = matrix[0].size();
	if(n == 0)
		return false;
	int i = 0,j = n-1;
	while(i<m && j>=0)
	{
		if(matrix[i][j] == target)
			return true;
		else if(matrix[i][j] < target)
			i++;
		else
			j--;
	}
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

