// leetcode combinations.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

void subsets(vector<vector<int> >& result,vector<int> &S,int num,vector<int>& temp,int start,int step)
{
	if(step == num)
	{
		result.push_back(temp);
		return;
	}
	if(start >= S.size())
		return;
	temp.push_back(S[start]);
	subsets(result,S,num,temp,start+1,step+1);
	temp.pop_back();
	subsets(result,S,num,temp,start+1,step);
}
vector<vector<int> > combine(int n, int k) {
	vector<int> s;
	for(int i=1;i<=n;i++)
		s.push_back(i);
	vector<vector<int> > result;
	vector<int> temp;
	subsets(result,s,k,temp,0,0);
	return result;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int> > result = combine(4,2);
	return 0;
}

