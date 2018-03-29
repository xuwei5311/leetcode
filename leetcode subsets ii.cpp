// leetcode subsets ii.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <map>
using namespace std;

void subsetsWithDup(vector<int> &S,vector<int>& temp,vector<vector<int> >& result,int start) //加入以temp为前缀start以后元素的组合为后缀的所有可能
{
	result.push_back(temp); //不包含后面的元素的一类

	for(int i=start;i<S.size();i++) //包含后面的元素的一类，并将这一大类按照包含的第一个元素i进一步分类
	{
		temp.push_back(S[i]);
		subsetsWithDup(S,temp,result,i+1);
		temp.pop_back();
		while(i+1 < S.size() && S[i] == S[i+1])  //已被包含
			i++;
	}
}

vector<vector<int> > subsetsWithDup(vector<int> &S) {
	vector<vector<int> > result;
	vector<int> temp;
	subsetsWithDup(S,temp,result,0);
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> s;
	s.push_back(1);
	s.push_back(2);
	vector<vector<int> > res = subsetsWithDup(s);
	return 0;
}

