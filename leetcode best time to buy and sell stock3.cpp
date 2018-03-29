// leetcode best time to buy and sell stock3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) 
{
	int n = prices.size();
	if(n <= 1)
		return 0;

	int buy1 = -prices[0];
	int sell1 = 0;
	int buy2 = -prices[0];
	int sell2 = 0;
	for(int i=1;i<n;i++)
	{
		buy1 = max(buy1,-prices[i]);
		sell1 = max(sell1,buy1+prices[i]);
		buy2 = max(buy2,sell1-prices[i]);
		sell2 = max(sell2,buy2+prices[i]);
	}
	return sell2;
}

int main()
{
	
	return 0;
}

