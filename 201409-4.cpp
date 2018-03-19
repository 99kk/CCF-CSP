#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define STOP -1

int dirx[] = {0, 0, -1, 1}, diry[] = {1, -1, 0, 0};
int board[1001][1001];
bool visited[1001][1001];
struct node{
	int x, y;
	node(int xx, int yy){
		x = xx; y = yy;
	}
};

int main(int argc, char** argv) {
	int n, m, k, d;
	cin>>n>>m>>k>>d;
	int i, j;
	int x, y;
	memset(board, 0, sizeof(board));
	memset(visited, false, sizeof(visited));
	queue<node> q, qq;
	for(i = 0; i < m; i++)
	{
		cin>>x>>y;
		q.push(node(x,y));
	}
	int c;
	for(i = 0; i < k; i++){
		cin>>x>>y>>c;
		board[x][y] += c;
	}
	for(i = 0; i < d; i++){
		cin>>x>>y;
		board[x][y] = STOP;
	}
	int steps = 0, sum = 0, num = 0;
	
	while(!q.empty()){
		
		while(!q.empty()){
			node cur = q.front();
			q.pop();
			x = cur.x; y = cur.y;
			visited[x][y] = true;
			//cout<<x<<" "<<y<<" "<<steps<<"*"<<board[x][y] <<endl;
			if(board[x][y] > 0){
				sum += board[x][y] * steps;
				
				num++;
				if(num ==k)
				{
					cout<<sum<<endl; return 0;
				}
			} 
			
			for(i = 0; i < 4; i++){
				if( x+dirx[i]>=1 && x+dirx[i]<=n && y+diry[i]>=1 && y+diry[i]<=n 
					&& board[x+dirx[i]][y+diry[i]] != STOP && !visited[x+dirx[i]][y+diry[i]])
				{
					qq.push(node(x+dirx[i], y+diry[i]));
					visited[x+dirx[i]][y+diry[i]] = true;
				}
			}
			
		}
		steps++;
		while(!qq.empty()){
			q.push(qq.front());
			qq.pop();
		}
	}
	
	cout<<sum<<endl;
	
	
	
	
	return 0;
}
