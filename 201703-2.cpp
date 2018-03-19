#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int m;
	cin>>m;
	int p,q;
	int i,j;
	int *a = new int[n+1];
	for(i = 1; i <= n; i++)
		a[i] = i;
		
	int pre;
	for(i = 0; i < m; i++)
	{
		cin>>p>>q;
		for(pre = 1; a[pre]!=p; pre++);
		if(q > 0)
		{
			for(j = 0; j < q; j++ )
			{
				a[pre+j] = a[pre+j+1];
			}
			a[pre+j] = p;
		}
		if(q < 0)
		{
			for(j = 0; j < -q; j++)
			{
				a[pre-j] = a[pre-j-1];
			}
			a[pre+q] = p;
		}
	}
	for(i = 1; i <= n; i++)
		cout<<a[i]<<" ";
	

	return 0;
}
