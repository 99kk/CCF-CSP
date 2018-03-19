#include <iostream>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n, *a, i,j;
	cin>>n;
	a = new int[n];
	
	int curMin;
	for(i = 0; i < n; i++)
	{
		cin>>a[i];		
	}
	curMin = abs(a[0] - a[1]);
	for(i = 0; i < n; i++)
	{
		for(j = i+1; j < n; j++)
		{
			curMin = min(curMin, abs(a[i]-a[j]));
		}
	}
	cout<<curMin<<endl;
	
	return 0;
}
