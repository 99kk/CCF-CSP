#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,k;
	cin>>n>>k;
	int i;
	int *a = new int[n];
	for(i = 0; i < n; i++)
		cin>>a[i];
		
	int getCakes = 0;
	int curWeight = 0;
	for(i = 0; i < n ;i++)
	{
		curWeight += a[i];
		if(curWeight >= k)
		{
			getCakes++;
			curWeight = 0;
		}
	}
	if(curWeight > 0) getCakes++;
	cout<<getCakes<<endl;
	
	
	
	return 0;
}
