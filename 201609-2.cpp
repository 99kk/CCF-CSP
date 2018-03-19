#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int *buy = new int[n];
	int i,j,k;
	for(i = 0; i < n; i++)
		cin>>buy[i];
		
	int tickets[101];
	for(i = 1; i<= 100; i++)
		tickets[i] = 0;
	
	bool succss;
	int cur;
	for(i = 0; i < n; i++)
	{
		succss = false;
		for(j = 0; j <= 19 && !succss; j++)
		{
			cur = 0;
			for(k = 5; tickets[j*5+k] != 1 && k >0; k--);
			cur = 5-k;
			if(cur >= buy[i])
			{
				for(int t = 1; t <= buy[i]; t++ )
				{
					tickets[j*5+k+t] = 1;
					cout<<j*5+k+t<<" ";
				}
				cout<<endl;
				succss = true;
			}
		}
		
		if(!succss)
		{
			cur = buy[i];
			for(j = 1; j <= 100 && cur > 0; j++)
			{
				if(tickets[j] == 0)
				{
					cur--;
					tickets[j] = 1;
					cout<<j<<" ";
				}
			}
			cout<<endl;
		}
		
		
	}
	
	
	return 0;
}
