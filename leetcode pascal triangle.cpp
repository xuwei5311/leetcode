// leetcode pascal triangle.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
using namespace std;

//�ٿ�pascal���ǣ������
vector<int> getRow(int rowIndex) 
{
	vector<int> result;
	if(rowIndex == 0)
		return result;
	int temp = 1;
	result.push_back(temp);
	for(int i=1;i<=rowIndex;i++)
	{
		temp = temp*(rowIndex-i+1)/i;
		result.push_back(temp);
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	getRow(2);
	return 0;
}

