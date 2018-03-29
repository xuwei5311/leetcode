// leetcode mutiplication.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
using namespace std;

string sum(string num1,string num2)
{
	int m = num1.size();
	int n = num2.size();
	int p = max(m,n)+1;
	num1 = string(p-m,'0')+num1;
	num2 = string(p-n,'0')+num2;
	string res(p,'0');
	int carry = 0;
	for(int i=0;i<p;i++)
	{
		int temp = num1[p-1-i]-'0'+num2[p-1-i]-'0'+carry;
		res[p-1-i] = (temp%10)+'0';
		carry = temp/10;
	}
	int index=0;
	while(index < p && res[index] == '0')
		index++;
	if(index == p)
		res = '0';
	else
		res = res.substr(index);
	return res;
}

string multiply(string num1, string num2) {
	int m = num1.size();
	int n = num2.size();
	string res="";
	for(int i=0;i<m;i++)
	{
		string mul(n+1,'0');
		int carry = 0;
		for(int j=0;j<n;j++)
		{
			int temp = (num1[m-1-i]-'0')*(num2[n-1-j]-'0')+carry;
			mul[n-j] = (temp%10)+'0';
			carry = temp/10;
		}
		mul[0] = carry+'0';
		res = sum(res,mul+string(i,'0'));
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string str = multiply("12","123");
	return 0;
}

