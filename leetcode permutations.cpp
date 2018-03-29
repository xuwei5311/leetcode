// leetcode permutations.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

void permute(vector<int> &num,vector<vector<int> >& res,vector<int>& path,vector<bool> used)
{
	if(num.size() == path.size())
	{
		res.push_back(path);
		return;
	}
	for(int i=0;i<num.size();i++)
	{
		if(!used[i])
		{
			used[i] = true;
			path.push_back(num[i]);
			permute(num,res,path,used);
			path.pop_back();
			used[i] = false;
		}
	}
}

vector<vector<int> > permute(vector<int> &num) {
	vector<vector<int> > res;
	vector<int> path;
	vector<bool> used(num.size(),false);
	sort(num.begin(),num.end());
	permute(num,res,path,used);
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	vector<vector<int> > res = permute(num);
	return 0;
}

