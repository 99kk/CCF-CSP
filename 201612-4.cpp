#include <iostream>
#include <cstring>
using namespace std;

const int INT_MAX2 = 0x7F7F7F7F;
const int N = 1000;

int v[N+1];
int sum[N+1];
int dp[N+1][N+1];
int p[N+1][N+1];


int main(int argc, char** argv) {
	int n;
	
	memset(dp, INT_MAX2, sizeof(dp));
	int i, j, k;
	
	cin>>n;
	sum[0] = 0;
	
	for(i = 1; i <= n; i++ )
	{
		cin>>v[i];
		sum[i] = sum[i-1] + v[i];
		dp[i][i] = 0;
		p[i][i] = i;
	}
	
	int val;
	for(int len = 2; len <= n; len++)
	{
		for(i = 1; i+len-1 <= n; i++)
		{
			j = i+len-1;
			for(k = p[i][j-1]; k <= p[i+1][j]; k++)
			{
				val = dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1];
				if(dp[i][j] > val)
				{
					dp[i][j] = val;
					p[i][j] = k;
				}
			}
		}
	}
	
	cout<<dp[1][n]<<endl;

	
	
	
	return 0;
}
