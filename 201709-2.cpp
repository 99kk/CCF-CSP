#include <iostream>
#include<algorithm>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n, k;
	cin>>n>>k;
	int *w = new int[k], *s = new int[k], *c = new int[k];
	int i,j, finish = 1;
	for(i = 0; i < k; i++)
	{
		cin>>w[i]>>s[i]>>c[i];
		finish = max(finish, s[i]+c[i]);
	}
		
	int *keys = new int[n+1];
	for(i = 1; i <= n; i++)
		keys[i] = i;
		
	int *returnKeys = new int[n+1], returnNum;
	for(i = 1; i <= finish; i++)
	{
		returnNum = 0;
		for(j = 0; j < k; j++)
		{
			if(i == s[j]+c[j])
			{
				returnKeys[returnNum] = w[j];
				returnNum++;
			}
		}
		sort(returnKeys, returnKeys+returnNum);
		for(j = 0; j < returnNum; j++)
		{
			int t;
			for( t = 1; keys[t]!=0; t++);
			keys[t] = returnKeys[j];
		}
		
		for(j = 0; j < k; j++)
		{
			if(i == s[j])
			{
				int t;
				for(t = 1; keys[t]!= w[j]; t++);
				keys[t] = 0;
			}
		}
		
		
	}
	
	for(i = 1; i <= n; i++)
		cout<<keys[i]<<" ";
	
	
	return 0;
}
