#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int *a = new int[n], *times = new int[n];
	int i,j;
	for(i = 0; i< n; i++)
	{
		cin>>a[i];
		times[i] = 0;
		
	}
	for(i = 0; i < n; i++)
	{
		times[a[i]]++;
		cout<<times[a[i]]<<" ";
	}
	

	
		
	return 0;
}
