// leetcode jump game.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

bool canJump(int A[], int n) {
	int pos = -1; //第i跳后能到达的最远位置
	for(int i=0;i<n;i++)
	{
		pos = max(pos,A[i]+i);
		if(pos >= n-1 || pos == i)
			break;
	}
	if(pos < n-1)
		return false;
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = {0};
	bool r = canJump(a, sizeof(a)/sizeof(int));
	return 0;
}

