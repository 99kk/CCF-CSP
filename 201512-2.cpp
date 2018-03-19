#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n, m;
	cin>>n>>m;
	int board[31][31];
	bool removed[31][31];
	int i, j, k;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
		{
			cin>>board[i][j];
			removed[i][j] = false;
		}
	
	int start, len;
	for(i = 1; i <= n; i++)
	{
		start = 1; len = 1;
		for(j = 2; j <= m; j++)
		{
			if(board[i][j] == board[i][j-1])
				len++;
			else
			{
				if(len >= 3)
				{
					for(k = start; k < start + len; k++)
						removed[i][k] = true;
				}
				start = j;
				len = 1;
			}
		}
		if(len >= 3)
		{
			for(k = start; k < start + len; k++)
				removed[i][k] = true;
		}
	}
	
	for(j = 1; j <= m; j++)
	{
		start = 1; len = 1;
		for(i = 2; i <= n; i++)
		{
			if(board[i][j] == board[i-1][j])
				len++;
			else
			{
				if(len >= 3)
				{
					for(k = start; k < start + len; k++)
						removed[k][j] = true;
				}
				start = i; len = 1;
			}
		}
		if(len >= 3)
		{
			for(k = start; k < start + len; k++)
				removed[k][j] = true;
		}
	}
	
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m; j++)
		{
			if(removed[i][j])
				cout<<0<<" ";
			else
				cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}
