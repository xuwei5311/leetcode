// leetcode word ladder ii.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <unordered_set>
#include <map>
#include <queue>
using namespace std;

//��bfs�ֺò㲢��ͼ����dfs
map<string,vector<string>> edges;
vector<vector<string>> result;

//ֻ��Ҫ�洢����ıߣ��������·��ʱ����end��start���ɣ�Ч�ʸ���
void GeneratePath(vector<string>& path,string start,string end)
{
	int n = edges[start].size();
	if(n == 0)
	{
		if(start == end)
		{
			path.push_back(end);
			reverse(path.begin(),path.end());   //��ת����������·��
			result.push_back(path);
			reverse(path.begin(),path.end());
			path.pop_back();
		}
		return;
	}

	path.push_back(start);
	for(int i=0;i<n;i++)
	{
		GeneratePath(path,edges[start][i],end);
	}
	path.pop_back();
}

vector<vector<string>> findLadders1(string start, string end, unordered_set<string> &dict) 
{
	dict.insert(start);
	dict.insert(end);
	//�Ƚ�ͼ���Ƚ������ͼ����㰴�յ�start��˳��ֲ㣬��ͬ��ڵ�֮��û�бߣ�������洦��
	unordered_set<string> currentLevelNodes;
	unordered_set<string> nextLevelNodes;
	currentLevelNodes.insert(start);
	unordered_set<string> unvisited = dict;
	unvisited.erase(start);
	while(!currentLevelNodes.empty() && !unvisited.empty())
	{
		for(unordered_set<string>::iterator it=currentLevelNodes.begin();it!=currentLevelNodes.end();it++)
		{
			int strlength = it->length();
			for(int i=0;i<strlength;i++)
			{
				for(int j=0;j<26;j++)
				{
					string temp = *it;
					temp[i] = 'a'+j;
					if(temp != *it && unvisited.count(temp) > 0)
					{
						//unvisited.erase(temp);        //��ͬ��ͼ��bfs��temp���Ժ�currentLevelNodes�еĶ���ڵ����ӣ���erase temp��ֻ�ܺ�һ���ڵ�������
						nextLevelNodes.insert(temp);
						edges[temp].push_back(*it);		//ֻ��Ҫ�洢����ıߣ��������·��ʱ����end��start���ɣ�Ч�ʸ��� 
					}
				}
			}
		}
		for(unordered_set<string>::iterator it=nextLevelNodes.begin();it!=nextLevelNodes.end();it++)
		{
			unvisited.erase(*it);   //��Ӧ������ѭ�����е�temp
		}
		currentLevelNodes = nextLevelNodes;
		nextLevelNodes.clear();
		if(currentLevelNodes.count(end) > 0)
		{
			vector<string> path;
			GeneratePath(path,end,start);
			break;
		}
	}

	return result;
} 

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
{
	unordered_set<string> dict;
	for(int i=0;i<wordList.size();i++)
		dict.insert(wordList[i]);
	return findLadders1(beginWord, endWord, dict);
}

int main()
{
	/*unordered_set<string> dict;
	string a[95] = {"si","go","se","cm","so","ph","mt","db","mb","sb",
		"kr","ln","tm","le","av","sm","ar","ci","ca","br",
		"ti","ba","to","ra","fa","yo","ow","sn","ya","cr",
		"po","fe","ho","ma","re","or","rn","au","ur","rh",
		"sr","tc","lt","lo","as","fr","nb","yb","if","pb",
		"ge","th","pm","rb","sh","co","ga","li","ha","hz",
		"no","bi","di","hi","qa","pi","os","uh","wm","an",
		"me","mo","na","la","st","er","sc","ne","mn","mi",
		"am","ex","pt","io","be","fm","ta","tb","ni","mr",
		"pa","he","lr","sq","ye"
	};
	for(int i=0;i<95;i++)
		dict.insert(a[i]);
	findLadders1("qa", "sq", dict) ;*/
	string a[6] = {"hot","dot","dog","lot","log","cog"};
	vector<string> wordList;
	for(int i=0;i<6;i++)
		wordList.push_back(a[i]);
	findLadders("hit", "cog",  wordList) ;
	return 0;
}

