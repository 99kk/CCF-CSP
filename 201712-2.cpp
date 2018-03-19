#include <iostream>

using namespace std;

int main(int argc, char** argv){
	int n, k, i,j;
	cin>>n>>k;
	int *kids = new int[n+1];
	for(i = 0; i <= n; i++)
	{
		kids[i] = 1;
	}
	int curKidsNum = n;
	int curNum = 1;
	int curID = 1;
	while(curKidsNum > 1)
	{
		//cout<<curKidsNum<<" "<<curID<<" "<<curNum<<endl;
		if(curNum % k == 0 || curNum % 10 == k)
		{
			kids[curID] = 0;
			curKidsNum--;
		}
		
		i = (curID+1)%n;
		if(i == 0) i = n;
		for(; ; i++)
		{
			curID = i%n;
			if(curID == 0) curID = n;
			
			if(kids[curID] == 1)
				break;
		}
	
		
		curNum++;
		
	}

	
	for(i = 1; i <= n; i++)
	{
		if(kids[i] == 1)
		{
			cout<<i<<endl;
			break;
		}
	}


	
	return 0;
	
}
