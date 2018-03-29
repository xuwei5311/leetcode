// leetcode permutation sequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;

//先把k cantor展开，再找到本轮和上一轮数据的对应关系即可
string getPermutation(int n, int k) {
	k = k-1;
	vector<int> base(10,1);
	for(int i=1;i<=9;i++)
	{
		base[i] = i*base[i-1];
	}
	string permutation(n,'0');
	for(int i=0;i<n;i++)
	{
		permutation[i] = k/base[n-1-i]+'0';
		k %= base[n-1-i];
	}
	for(int i=n-1;i>=1;i--)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(permutation[i] >= permutation[j])
				permutation[i]++;
		}
	}
	for(int i=0;i<n;i++)
		permutation[i]++;
	return permutation;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string str = getPermutation(3,3);
	return 0;
}

