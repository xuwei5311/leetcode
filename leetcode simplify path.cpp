// leetcode simplify path.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <stack>
using namespace std;

string simplifyPath(string path) {
	size_t n = path.length();
	if(n == 0 || path[0] != '/')
		return "";
	stack<string> s;
	size_t start = 1;
	while(start < n)
	{
		size_t end = path.find('/',start);
		int len = end-start;
		if(end == string::npos)
			len = n-start;
		string tmp = path.substr(start,len);
		if(tmp == "..")
		{
			if(!s.empty())
				s.pop();
		}
		else if(!(tmp.empty() || tmp == "."))
		{
			s.push(tmp);
		}
		if(end == string::npos)
			break;
		start = end+1;
	}
	if(s.empty())
		return "/";
	string res = "";
	string tmp1 = "/";
	while(!s.empty())
	{
		string tmp = s.top();
		s.pop();
		res = tmp1+tmp+res;
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string path = simplifyPath("/");
	return 0;
}

