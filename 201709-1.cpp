#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int n;
	cin>>n;
	n = n / 10;
	int i, j, k;
	int curMax = n;
	int left = 0;
	for(i = 0; i <= n/3; i++)
		for(j = 0; j <= (n-3*i)/5; j++)
			{
				left = n- i*3 - j*5;
				curMax = max(curMax, i*4+j*7+left);
			}
	
	cout<<curMax<<endl;
	return 0;
}
