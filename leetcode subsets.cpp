// leetcode subsets.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
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
	/*for(int i=start;i<S.size();i++)
	{
		temp.push_back(S[i]);
		subsets(result,S,num,temp,i+1,step+1);
		temp.pop_back();
	}*/
	temp.push_back(S[start]);
	subsets(result,S,num,temp,start+1,step+1);
	temp.pop_back();
	subsets(result,S,num,temp,start+1,step);
}

//输出结果按子集的元素个数排列
vector<vector<int> > subsets(vector<int> &S) {
	sort(S.begin(),S.end());
	vector<vector<int> > result;
	for(int num=0;num<=S.size();num++)
	{
		vector<int> temp;
		subsets(result,S,num,temp,0,0);
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int data[] = {1,2,3};
	vector<int> s(begin(data),end(data));
	sort(s.begin(),s.end());
	vector<vector<int> > result = subsets(s);
	return 0;
}

