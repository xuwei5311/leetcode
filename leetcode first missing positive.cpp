// leetcode first missing positive.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

int firstMissingPositive(int A[], int n) {
	for(int i=0;i<n;i++)
	{
		while(A[i] != i+1 && A[i] >= 1 && A[i] <= n && A[i] != A[A[i]-1])
		{
			swap(A[i],A[A[i]-1]);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(A[i] != i+1)
			return (i+1);
	}
	return n+1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = {4,1,2,4};
	int res = firstMissingPositive(a,sizeof(a)/sizeof(int));
	return 0;
}

