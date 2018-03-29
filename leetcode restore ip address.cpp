// leetcode restore ip address.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
using namespace std;

int strtoint(string str)
{
	int n = str.length();
	int x = 0;
	for(int i=0;i<n;i++)
	{
		x = x*10 + str[i] - '0';
	}
	return x;
}

void restoreIpAddresses(string& s,int start,vector<string>& result,int step,vector<int>& path)
{
	if(step == 4 && start == s.length())
	{
		string str = "";
		for(int i=0;i<path.size()-1;i++)
		{
			str += s.substr(path[i],path[i+1]-path[i]);
			str += ".";
		}
		str += s.substr(path[path.size()-1],s.length()-path[path.size()-1]);
		result.push_back(str);
		return;
	}
	
	if(s[start] != '0')
	{
		for(int end=start;end<=start+2 && end<s.length();end++)
		{
			int x = strtoint(s.substr(start,end-start+1));
			if(x >= 0 && x <= 255)
			{
				path.push_back(start);
				restoreIpAddresses(s,end+1,result,step+1,path);
				path.pop_back();
			}
		}
	}
	else
	{
		path.push_back(start);
		restoreIpAddresses(s,start+1,result,step+1,path);
		path.pop_back();
	}
}

vector<string> restoreIpAddresses(string s)
{
	vector<string> result;
	vector<int> path;
	restoreIpAddresses(s,0,result,0,path);
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

