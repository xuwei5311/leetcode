// leetcode search a 2d matrix.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
using namespace std;

/*����ѡȡ���Ͻ����֣���������ֵ���Ҫ���ҵ����֣����ҹ��̽�������������ִ���Ҫ���ҵ����֣�
ȥ�������������У����������С��Ҫ���ҵ����֣���ȥ�������������С��ظ���������ֱ���ҵ�Ҫ��
�ҵ����֣����߲��ҷ�ΧΪ�ա�*/
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

