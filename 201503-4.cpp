#include <iostream>
#include <set>
#include <cstring>
#include <queue>
using namespace std;


set<int> edge[20001];
bool visited[20001];
queue<int> q, qq;
int start, length = 0;
int bfs(int start)
{
	q.push(start);
	visited[start] = true;
	int cur;
	while(!q.empty())
	{
		
		while(!q.empty())
		{	cur = q.front();
			q.pop();
			for(set<int>::iterator it = edge[cur].begin(); it != edge[cur].end(); it++)
			{
				if(!visited[*it])
				{
					qq.push(*it);
					visited[*it] = true;
				}
			}	
		}
		if(!qq.empty()) length++;
		while(!qq.empty())
		{
			q.push(qq.front());
			qq.pop();
		}
		
	}
	return cur;
	
}

int main(int argc, char** argv) {
	int n,m;
	cin>>n>>m;
	
	int i, j, father;
	for(i = 2; i <= n; i++)
	{
		cin>>father;
		edge[i].insert(father);
		edge[father].insert(i);
	}
	for(i = 1; i <= m; i++)
	{
		cin>>father;
		edge[i+n].insert(father);
		edge[father].insert(i+n);
	}
	
	memset(visited, false, sizeof(visited));
	int s = bfs(1);
	length = 0;
	memset(visited, false, sizeof(visited));
	s = bfs(s);
	cout<<length<<endl;
	
	
	return 0;
}
