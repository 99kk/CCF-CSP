#include <iostream>
#include <cstring>
#include <set>
#include <stack>
using namespace std;


bool instack[10001];
set<int> edge[10001];
stack<int> s;
int dfn[10001], low[10001], index = 0;;
int inComponent[10001];
int res = 0;

void f(int i)
{
	dfn[i] = low[i] = index++;
	instack[i] = true;
	s.push(i);
	for(set<int>::iterator it = edge[i].begin(); it != edge[i].end(); it++)
	{
		if(dfn[*it] == -1)
		{
			f(*it);
			low[i] = min(low[i], low[*it]);
		}
		else if(instack[*it]) low[i] = min(low[i], dfn[*it]);
	}
	if(dfn[i] == low[i])
	{
		int num = 0;
		while(!s.empty() && s.top() != i)
		{
			instack[s.top()] = false;
			num++;
			s.pop();
		}
		instack[s.top()] = false;
		num++;
		s.pop();
		res += num * ( num -1) /2;
	}
	
}

int main(int argc, char** argv) {
	int n, m, a, b;
	cin>>n>>m;
	int i, j;
	for(i = 0; i < m; i++)
	{
		cin>>a>>b;
		edge[a].insert(b);
	}
	
	for(i = 1; i <= n; i++)
	{
		dfn[i] = low[i]  =inComponent[i]= -1;
		instack[i] = false;
	}
	for(i = 1; i <= n; i++)
	{
		if(dfn[i] == -1)
			f(i);
	}
	cout<<res<<endl;
	
	return 0;
}
