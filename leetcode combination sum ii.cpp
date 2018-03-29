// leetcode combination sum ii.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

void combinationSum2(vector<vector<int> >& res,vector<int>& path,vector<int> &num, int start,int target)
{
	if(target == 0)
	{
		res.push_back(path);
		return;
	}
	for(int i=start;i<num.size();i++)
	{
		if(num[i] > target)
			break;
		path.push_back(num[i]);
		combinationSum2(res,path,num,i+1,target-num[i]);
		path.pop_back();
		while(i+1 < num.size() && num[i+1] == num[i])
			i++;
	}
}

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
	sort(num.begin(),num.end());
	vector<vector<int> > res;
	vector<int> path;
	combinationSum2(res,path,num,0,target);
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int data[] = {10,1,2,7,6,1,5};
	vector<int> num;
	for(int i=0;i<sizeof(data)/sizeof(int);i++)
		num.push_back(data[i]);
	vector<vector<int> > res = combinationSum2(num,8);
	return 0;
}

