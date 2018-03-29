// leetcode palindrome partitioning.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
using namespace std;

bool ispalindrome(string& str)
{
	string str1 = str;
	reverse(str.begin(),str.end());
	if(str1 == str)
		return true;
	return false;
}

void partition(string& s,int start,vector<vector<string>>& result,vector<string>& temp)
{
	if(start >= s.length())
	{
		result.push_back(temp);
		return;
	}
	for(int i=start;i<s.length();i++)
	{
		string str = s.substr(start,i-start+1);
		if(ispalindrome(str))
		{
			temp.push_back(str);
			partition(s,i+1,result,temp);
			temp.pop_back();
		}
	}
}

vector<vector<string>> partition(string s) {
	vector<vector<string>> result;
	if(s.length() == 0)
		return result;
	vector<string> temp;
	partition(s,0,result,temp);
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	partition("aab");
	return 0;
}

