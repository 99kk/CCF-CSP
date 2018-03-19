#include <iostream>
#include<math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n, *a;
	cin>>n;
	a = new int[n];
	int i, j;
	for(i = 0; i < n; i++)
		cin>>a[i];
		
	int maxDif = abs(a[0]- a[1]);
	for(i = 1; i < n; i++)
	{
		maxDif = max(maxDif, abs(a[i]- a[i-1]));
	}
	
	cout<<maxDif<<endl;
	
	return 0;
}
