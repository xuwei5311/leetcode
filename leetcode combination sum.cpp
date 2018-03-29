// leetcode combination sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

void combinationSum(vector<vector<int> >& res,vector<int>& path,vector<int> &candidates,int start, int target)
{
	if(target == 0)
	{
		res.push_back(path);
		return;
	}
	for(int i=start;i<candidates.size();i++)
	{
		if(candidates[i] > target)
			break;
		path.push_back(candidates[i]);
		combinationSum(res,path,candidates,i,target-candidates[i]);
		path.pop_back();
	}
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
	vector<vector<int> > res;
	vector<int> path;
	sort(candidates.begin(),candidates.end());
	combinationSum(res,path,candidates,0,target);
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = {8,7,4,3};
	int target = 11;
	vector<int> candidates;
	for(int i=0;i<sizeof(a)/sizeof(int);i++)
		candidates.push_back(a[i]);
	vector<vector<int> > res = combinationSum(candidates, target);
	return 0;
}

