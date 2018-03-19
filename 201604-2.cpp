#include <iostream>
using namespace std;

//wa  90 points

int main(int argc, char** argv) {
	int board[20][10], input[4][4], col;
	int i, j;
	for(i = 0; i < 15; i++)
		for(j = 0; j < 10; j++)
			cin>>board[i][j];
	
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			cin>>input[i][j];
	
	cin>>col;
	
	for(i = 15; i < 20; i++)
		for(j = 0; j < 10; j++)
			board[i][j] = 1;

	
	int k;
	bool crash = false;
	for(k = 0; k <= 14 && !crash; k++)
	{
		for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++)
			{
				if(board[i+k][j+col-1] == 1 && input[i][j] == 1)
				{
					crash = true;
					
				}
					
			}
		
		if(crash) break;
	}

	k--;
	
	for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++)
			{
				if(board[i+k][j+col-1] == 0)
					board[i+k][j+col-1] = input[i][j];
			}
	
	
	for(i = 0; i < 15; i++)
	{
		for(j = 0; j < 10; j++)
			cout<<board[i][j]<<" ";
			
		cout<<endl;
	}	
	
	
	
	return 0;
}
