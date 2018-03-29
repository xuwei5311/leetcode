// leetcode sort colors.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void sortColors(int A[], int n) {
	if(n == 0 || n == 1)
		return;
	int pos0 = 0;
	int pos2 = n-1;
	int i = 0;
	//保持：pos0前面由0和1顺序排列，pos2后面全是2
	while(i <= pos2)
	{
		if(A[i] == 1)
			i++;
		else if(A[i] == 0)
		{
			swap(A[i],A[pos0]);
			pos0++;
			i++;
		}
		else
		{
			swap(A[i],A[pos2]);
			pos2--;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = {0,0,2,2,1,1,2,1};
	sortColors(a,8);
	return 0;
}

