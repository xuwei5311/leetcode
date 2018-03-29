// leetcode permutation sequence.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;

//�Ȱ�k cantorչ�������ҵ����ֺ���һ�����ݵĶ�Ӧ��ϵ����
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

