// leetcode insert interval.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

//按照intervals分成2n+1个区域
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
	int n = intervals.size();
	int start = -1;
	int end = -1;
	for(int i=0;i<n;i++)
	{
		if(start == -1)
		{
			if(newInterval.start < intervals[i].start)
			{
				start = 2*i;
			}
			else if(newInterval.start <= intervals[i].end)
			{
				start = 2*i+1;
			}
		}
		if(end == -1)
		{
			if(newInterval.end < intervals[i].start)
			{
				end = 2*i;
			}
			else if(newInterval.end <= intervals[i].end)
			{
				end = 2*i+1;
			}	
		}
		else
			break;
	}
	if(start == -1)
		start = 2*n;
	if(end == -1)
		end = 2*n;
	vector<Interval> res(intervals);
	if(start == end)
	{
		if(start%2 == 0)
			res.insert(res.begin()+start/2,newInterval);
	}
	else
	{
		int x = start/2;
		int y = (end-1)/2;
		res[x].start = min(res[x].start,newInterval.start);
		res[x].end = max(res[y].end,newInterval.end);
		res.erase(res.begin()+x+1,res.begin()+y+1);
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<Interval> intervals;
	intervals.push_back(Interval(1,5));
	Interval newInterval(0,0);
	insert(intervals,newInterval);
	return 0;
}

