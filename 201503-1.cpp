#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,m;
	cin>>n>>m;
	int **a = new int*[n];
	int i,j;
	for(i = 0; i < n; i++)
		a[i] = new int[m];
	
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			cin>>a[i][j];
	
	for(j = m-1; j >=0; j--) 
	{
		for(i = 0; i < n; i++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
		
			
		
	
	
	return 0;
}
