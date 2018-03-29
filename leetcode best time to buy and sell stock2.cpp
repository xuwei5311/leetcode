// leetcode best time to buy and sell stock2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if(n <= 1)
        return 0;
 
    int start = prices[0];
    int pre = start;
    int i=1;
    int profit = 0;
    while(i<n)
    {
        while(i<n && prices[i] >= pre)
        {
            pre = prices[i];
            i++;
        }
        profit += (pre-start);
        while(i<n && prices[i] <= pre)
        {
            pre = prices[i];
            i++;
        }
        start = pre;
    }
    return profit;
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

