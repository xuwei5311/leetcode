// leetcode jump game ii.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
using namespace std;

//����һ�ⲻһ��������������û��0���������ܵ����һ��λ��
int jump(int A[], int n) {
	vector<int> res(n,n);
	res[n-1] = 0;
	for(int i=n-2;i>=0;i--)
	{
		if(i+A[i] >= n-1)
			res[i] = 1;
		else
		{
			for(int j=1;j<=A[i];j++)
				res[i] = min(res[i],1+res[i+j]);
		}
	}
	return res[0];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int A[] ={2,3,1,1,4};
	int res = jump(A,5);
	return 0;
}

