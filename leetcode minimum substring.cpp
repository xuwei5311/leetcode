// leetcode minimum substring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <unordered_map>
#include <string>
using namespace std;

string minWindow(string S, string T) {
	if(T.empty())
		return "";
	unordered_map<char,int> tset;
	for(int i=0;i<T.length();i++)
	{
		if(tset.count(T[i]))
			tset[T[i]]++;
		else
			tset[T[i]] = 1;
	}
	unordered_map<char,int> u; //start到end之间包含在T中的字符的集合
	//查找第一个满足条件的子串（从0开始）
	int end = 0;
	unordered_map<char,int> tsetcp(tset);
	for(;end<S.length();end++)
	{
		char c = S[end];
		if(!tset.count(c))
			continue;
		if(u.count(c))
			u[c]++;
		else
			u[c] = 1;
		if(tsetcp.count(c))
		{
			--tsetcp[c];
			if(tsetcp[c] == 0)
			{
				tsetcp.erase(c);
				if(tsetcp.empty())
					break;
			}
		}
	}
	if(end == S.length())
		return "";
	string result = S.substr(0,end+1);
	for(int start=1;start <= S.length()-T.length();start++)
	{
		string res = "";
		char c = S[start-1];
		if(tset.count(c))
			u[c]--;
		if(!tset.count(c) || u[c] >= tset[c])
		{
			res = S.substr(start,end-start+1);
		}
		else
		{
			while(++end < S.length())
			{
				char d = S[end];
				if(d == c)
				{
					u[d]++;
					res = S.substr(start,end-start+1);
					break;
				}
				else
				{
					if(tset.count(d))
						u[d]++;
				}
			}
		}
		if(res.empty())
			break;
		else if(res.length() < result.length())
			result = res;
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string str = minWindow("ADOBECODEBANC", "BAC" );
	return 0;
}

