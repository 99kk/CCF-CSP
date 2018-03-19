#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int mat[501][501];
	int i,j;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			cin>>mat[i][j];
			
	int *seq = new int[n*n+1], index = 1;
	int x = 1, y = 1;
	
	for(i = 2; i <= n*2; i++)
	{
		if(i % 2 == 0)
		{
			for(j = max(1,i-n); j <= min(n, i-1); j++)
			{
				seq[index++] = mat[i-j][j];
			}
		}
		else
		{
			for(j = max(1, i-n); j <= min(n, i-1); j++)
			{
				seq[index++] = mat[j][i-j];
			}
		}
	}
	
	for(i = 1; i <= n*n; i++)
		cout<<seq[i]<<" ";
	
	
	return 0;
}
