#include <iostream>
#include<algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n, *a;
	cin>>n;
	a = new int[n+1];
	int i,j;
	for(i = 1; i <= n; i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int key = a[(n+1)/2];
	if(n == 1) 
	{
		cout<<a[1]<<endl;
		return 0;
	}
	if(n == 2)
	{
		if(a[1]==a[2]) cout<<a[1]<<endl;
		else cout<<-1<<endl;
		return 0;
	}
	
	int gt = 0, lt = 0;
	for(i = 1; i <= n; i++)
	{
		if(a[i] > key) gt++;
		if(a[i] < key) lt++;
	}
	//cout<<gt<<" "<<lt<<endl;
	
	if(gt == lt) cout<<key<<endl;
	else cout<<-1<<endl;
	
	
	
	
	
	return 0;
}
