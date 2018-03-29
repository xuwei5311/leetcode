// leetcode merge intervals.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

bool compare(Interval& a,Interval& b)
{
	return (a.start < b.start);
}

vector<Interval> merge(vector<Interval> &intervals) {
	sort(intervals.begin(),intervals.end(),compare);
	stack<Interval> s;
	for(vector<Interval>::iterator it = intervals.begin();it!=intervals.end();it++)
	{
		if(s.empty())
		{
			s.push(*it);
			continue;
		}
		if(s.top().end >= it->start)
		{
			s.top().end = max(s.top().end,it->end);
		}
		else
		{
			s.push(*it);
		}
	}
	vector<Interval> res;
	while(!s.empty())
	{
		res.push_back(s.top());
		s.pop();
	}
	reverse(res.begin(),res.end());
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<Interval> intervals;
	intervals.push_back(Interval(1,3));
	intervals.push_back(Interval(2,6));
	intervals.push_back(Interval(8,10));
	intervals.push_back(Interval(15,18));
	merge(intervals);
	return 0;
}

