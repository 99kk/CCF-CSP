#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int *a = new int[n];
	int i, j;
	for(i = 0; i < n; i++)
		cin>>a[i];
	
	int times[1001];
	for(i = 0; i <= 1000; i++)
		times[i] = 0;
	
	int num = 0;
	for(i = 0; i < n; i++)
	{
		if(times[a[i]] == 0)
			num++;
		times[a[i]]++;
		
	}
	
	int curMax, curNum;
	for(i = 0; i < num; i++)
	{
		curMax = times[a[0]]; curNum = a[0];
		for(j = 0; j < n; j++)
		{
			if((times[a[j]] > curMax && times[a[j]]> 0) || (times[a[j]] == curMax && a[j] < curNum) )
			{
				curMax = times[a[j]]; curNum = a[j];
			}
		}
		
		cout<<curNum<<" "<<curMax<<endl;
		times[curNum] = 0;
	}
	
	
	
	return 0;
}
