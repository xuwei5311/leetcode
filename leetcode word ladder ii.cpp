// leetcode word ladder ii.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <unordered_set>
#include <map>
#include <queue>
using namespace std;

//先bfs分好层并建图，再dfs
map<string,vector<string>> edges;
vector<vector<string>> result;

//只需要存储逆向的边，最后生成路径时，从end到start生成，效率更高
void GeneratePath(vector<string>& path,string start,string end)
{
	int n = edges[start].size();
	if(n == 0)
	{
		if(start == end)
		{
			path.push_back(end);
			reverse(path.begin(),path.end());   //翻转，生成正向路径
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
	//先建图，比较特殊的图，结点按照到start的顺序分层，且同层节点之间没有边，方便后面处理
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
						//unvisited.erase(temp);        //不同于图的bfs，temp可以和currentLevelNodes中的多个节点连接，若erase temp则只能和一个节点连接了
						nextLevelNodes.insert(temp);
						edges[temp].push_back(*it);		//只需要存储逆向的边，最后生成路径时，从end到start生成，效率更高 
					}
				}
			}
		}
		for(unordered_set<string>::iterator it=nextLevelNodes.begin();it!=nextLevelNodes.end();it++)
		{
			unvisited.erase(*it);   //对应于上面循环体中的temp
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

