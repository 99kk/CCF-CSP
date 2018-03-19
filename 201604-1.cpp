#include <iostream>
using namespace std;


int main(int argc, char** argv) {
	int n;
	cin>>n;
	int *a = new int[n];
	int i,j;
	for(i = 0; i < n; i++)
	{
		cin>>a[i];
	} 
	 
	int turn = 0;
	for(i = 1; i < n-1; i++)
	{
		if(a[i]>a[i-1] && a[i]>a[i+1]) turn++;
		if(a[i]<a[i-1] && a[i]<a[i+1]) turn++;
	}
	cout<<turn<<endl;
	
	return 0;
}
