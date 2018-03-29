// leetcode trapping rain water.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>
using namespace std;

struct rect
{
	int w;
	int h;
	rect(int i,int j):w(i),h(j){}
};

int trap(int A[], int n) {
	if(n == 0)
		return 0;
	int sum = 0;
	stack<rect> s; //栈中元素始终按照高度降序排列
	for(int i=0;i<n;i++)
	{
		while(!s.empty() && A[i] > s.top().h)
		{
			rect temp = s.top();
			s.pop();
			if(!s.empty())
			{
				rect temp1 = s.top();
				if(temp1.h > A[i])
				{
					sum += (A[i]-temp.h)*temp.w;
					s.push(rect(temp.w,A[i]));
				}
				else
				{
					sum += (temp1.h-temp.h)*temp.w;
					s.pop();
					s.push(rect(temp.w+temp1.w,temp1.h));
				}
			}
		}
		if(s.empty() || A[i] < s.top().h)
			s.push(rect(1,A[i]));
		else
		{
			rect temp = s.top();
			s.pop();
			s.push(rect(1+temp.w,A[i]));
		}
	}
	return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = {4,2,0,3,2,5};
	int res = trap(a,sizeof(a)/sizeof(int));
	return 0;
}

