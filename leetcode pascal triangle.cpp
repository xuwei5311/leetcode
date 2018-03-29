// leetcode pascal triangle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

//百科pascal三角，组合数
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

