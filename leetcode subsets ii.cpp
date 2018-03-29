// leetcode subsets ii.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <map>
using namespace std;

void subsetsWithDup(vector<int> &S,vector<int>& temp,vector<vector<int> >& result,int start) //������tempΪǰ׺start�Ժ�Ԫ�ص����Ϊ��׺�����п���
{
	result.push_back(temp); //�����������Ԫ�ص�һ��

	for(int i=start;i<S.size();i++) //���������Ԫ�ص�һ�࣬������һ���ఴ�հ����ĵ�һ��Ԫ��i��һ������
	{
		temp.push_back(S[i]);
		subsetsWithDup(S,temp,result,i+1);
		temp.pop_back();
		while(i+1 < S.size() && S[i] == S[i+1])  //�ѱ�����
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

