// leetcode valid number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//正则表达式的匹配
bool isNumber(const char *s,int step)
{
	if(*s == '\0')
	{
		if(step >= 2)
			return true;
		else
			return false;
	}
	if(step == 0)
	{
		if(*s == ' ')
			return isNumber(s+1,step);
		else
			return isNumber(s,step+1);
	}
	if(step == 1)
	{
		if(*s == '+' || *s == '-')
			return isNumber(s+1,step+1);
		else
			return isNumber(s,step+1);
	}
	if(step == 2)
	{
		if(*s == '0')
			return isNumber(s+1,step+1);
		else if(*s >= '1' && *s <= '9')
		{
			++s;
			while(*s >= '0' && *s <= '9')
			{
				++s;
			}
			return isNumber(s,step+1);
		}
		else
			return isNumber(s,step+1);
	}
	if(step == 3)
	{
		if(*s == '.' || *s == 'e' || *s == 'E')
			return isNumber(s+1,step+1);
		else
			return isNumber(s+1,step+2);
	}
	if(step == 4)
	{
		if(*s >= '0' && *s <= '9')
			return isNumber(s+1,step);
		else
			return isNumber(s+1,step+1);
	}
	if(step == 5)
	{
		if(*s == ' ')
			return isNumber(s+1,step);
		else
			return false;
	}
	return false;
}

bool isNumber(const char *s) {
	return isNumber(s,0);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 2e00;
	bool res = isNumber("1 ");
	return 0;
}

