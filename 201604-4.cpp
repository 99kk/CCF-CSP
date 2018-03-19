#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct node
{
	int x, y, steps;
	node(int xx, int yy, int s){
		x = xx; y = yy; steps = s;
	}
};

bool danger[101][101][300];




int main(int argc, char** argv) {
	int n, m, t, r, c, a, b;
	int i, j;
	memset(danger, 0, sizeof(danger));
	cin>>n>>m>>t;
	for(i = 0; i < t; i++)
	{
		cin>>r>>c>>a>>b;
		for(j = a; j <= b; j++) danger[r][c][j] = true;
	}
	queue<node> q;
	q.push(node(1,1,0));
	int curMin = 99999999;
	while(!q.empty())
	{
		node tmp = q.front();
		q.pop();
		if(tmp.x == n && tmp.y == m)
		{
			curMin = min(curMin, tmp.steps);
			continue;
		}
		
		if(tmp.steps >= curMin) continue;
		
		if(tmp.x+1 <= n && !danger[tmp.x+1][tmp.y][tmp.steps+1]){
			q.push(node(tmp.x+1, tmp.y, tmp.steps+1));
			danger[tmp.x+1][tmp.y][tmp.steps+1] = true;
		} 
		if(tmp.y+1 <= m && !danger[tmp.x][tmp.y+1][tmp.steps+1]){
			q.push(node(tmp.x, tmp.y+1, tmp.steps+1));
			danger[tmp.x][tmp.y+1][tmp.steps+1] = true;
		}
		if(tmp.x-1 >= 1 && !danger[tmp.x-1][tmp.y][tmp.steps+1]){
			q.push(node(tmp.x-1, tmp.y, tmp.steps+1));
			danger[tmp.x-1][tmp.y][tmp.steps+1] = true;
		} 
		if(tmp.y-1 >=1 && !danger[tmp.x][tmp.y-1][tmp.steps+1]){
			q.push(node(tmp.x, tmp.y-1, tmp.steps+1));
			danger[tmp.x][tmp.y-1][tmp.steps+1] = true;
		}
		
		
	}
	cout<<curMin<<endl;
	
	
	return 0;
}
