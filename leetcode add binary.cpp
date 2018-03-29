// leetcode add binary.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
using namespace std;

string addBinary(string a, string b) {
	int m = a.length();
	int n = b.length();
	if(m<n)
	{
		string c(n-m,'0');
		a = c+a;
	}
	if(m>n)
	{
		string c(m-n,'0');
		b = c+b;
	}
	int p = a.length();
	unsigned int carry = 0;
	string sum(p+1,'0');
	for(int i=0;i<p;i++)
	{
		unsigned int A = a[p-1-i]-'0';
		unsigned int B = b[p-1-i]-'0';
		sum[p-i] = carry^A^B + '0';
		carry = (A&B) | ((A|B)&carry);
	}
	sum[0] = carry + '0';
	int j=0;
	while(j<=p && sum[j] == '0')
		j++;
	if(j == p+1)
		sum = '0';
	else
		sum = sum.substr(j);
	return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string sum = addBinary("10","1");
	return 0;
}

