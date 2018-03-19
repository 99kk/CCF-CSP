#include <iostream>
#include <vector>
#include <cstring> 
#include <algorithm>
#include <set>
#include <stack>
using namespace std;


set<int> g[10010];
int degree[10010];

stack<int> path;
bool visited[10010][10010];
int v[10010];
class UF{
	int length;
public:
	UF(int n){
		length = n;
		for(int i = 0; i<= n; i++)
			v[i] = i;
	}
	int Find(int x)
	{
		if(x == v[x])
			return x;
		else
			return v[x] = Find(v[x]);
	}
	
	bool Union(int x, int y){
		x = Find(x);
		y = Find(y);
		if(x == y) return false;
		else
		{
			v[x] = y;
			return true;
		}
	}
};


void dfs(int cur)
{
	for(set<int>::iterator it = g[cur].begin(); it != g[cur].end(); it++)
	{
		if(!visited[cur][*it]){
			visited[cur][*it] = true;
			visited[*it][cur] = true;
			dfs(*it);
		}
	}
	path.push(cur);
}


int main(int argc, char** argv) {
	int n, m, a, b ;
	cin>>n>>m;
	int i, j;
	memset(degree, 0, sizeof(degree));
	memset(visited, false, sizeof(visited));
	UF uf(n);
	for(i = 0; i < m; i++)
	{
		cin>>a>>b;
		uf.Union(a,b);
		g[a].insert(b);
		g[b].insert(a);
		degree[a]++; degree[b]++;
	}
	
	int root = uf.Find(1);
	for(i = 2; i <= n; i++)
	{
		if(root != uf.Find(i))
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	
	int odds = 0;
	for(i = 1; i <= n; i++)
	{
		if(degree[i] % 2 != 0)
			odds++;
	}
	if(odds > 2)
	{
		cout<<-1<<endl;
		return 0;
	}
	
	if(odds == 2 && degree[1] % 2 == 0)
	{
		cout<<-1<<endl;
		return 0;
	}

	dfs(1);
	int t;
	while(!path.empty())
	{
		t = path.top();
		path.pop();
		cout<< t << " ";
	}
	cout << endl; 
	
	return 0;
}
