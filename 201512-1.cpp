#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	
	int sum = 0;
	while(n >= 10)
	{
		sum += n % 10;
		n /= 10;
		
	}
	sum+=n;
	cout<<sum<<endl;
	
	
	return 0;
}
