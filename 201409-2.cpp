#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int a[101][101];
	int i, j, k;
	for(i = 0; i <= 100; i++)
		for(j = 0; j <= 100; j++)
		{
			a[i][j] = 0;
		}
	int xl, yl, xr, yr;
	for(i = 0; i < n; i++)
	{
		cin>>xl>>yl>>xr>>yr;
		for(j = xl; j < xr; j++)
			for(k = yl; k < yr; k++)
			{
				a[j][k]++;
			}
	}
	
	int cnt = 0;
	for(i = 0; i < 100; i++)
	{
		for(j = 0; j < 100; j++)
		{
			if(a[i][j]> 0)
				cnt++;
			//cout<<a[i][j]<<" ";
		}
		//cout<<endl;
			
	}
	cout<<cnt<<endl;
	
	return 0;
}
