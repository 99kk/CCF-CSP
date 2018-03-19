#include <iostream>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	 cin>>n;
	 int *a = new int[n];
	int i,j;
	for(i = 0; i < n; i++)
		cin>>a[i];
	sort(a, a+n);
	
	int num = 0;
	for(i = 1; i < n; i++)
	{
		if(a[i]-a[i-1] == 1)
		num++;
	}
	cout<<num;
	
	
	
	return 0;
}
