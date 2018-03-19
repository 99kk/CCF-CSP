#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n, m;
	cin>>n>>m;
	int *x1 = new int[n], *x2 = new int[n], *y1 = new int[n], *y2 = new int[n];
	int *order = new int[n];
	int i,j;
	for(i = 0; i < n; i++)
	{
		cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
		order[i] = i;
	}
	
	int x, y, curOrder, curWin;
	for(i = 0; i < m; i++)
	{
		cin>>x>>y;
		curOrder = -1;
		for(j = 0; j < n; j++)
		{
			if( x1[j]<=x && x <= x2[j] && y1[j]<= y && y <= y2[j] && order[j] > curOrder  )
			{
				curOrder = order[j];
				curWin = j;
			}
		}
		if(curOrder == -1)
		{
			cout<<"IGNORED"<<endl;
		}
		else
		{
			cout<<curWin+1<<endl;
			for(j = 0; j < n; j++)
			{
				if(order[j]> curOrder)
					order[j]--;
			}
			order[curWin] = n-1;
		}
	}
		
		

	
	
	
	
	return 0;
}
