#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int *a = new int[n];
	int i,j;
	for(i = 0; i <n; i++)
	cin>>a[i];
	
	int num = 0;
	for(i = 0; i< n; i++)
		for(j = i+1; j < n; j++)
		{
			if(a[i]+a[j] == 0)
				num++;
		}
	
	cout<<num;
	
	return 0;
}
