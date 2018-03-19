#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char isbn[15];
	cin.getline(isbn, 14);
	int verify = (isbn[0]-'0') + (isbn[2]-'0')*2 + (isbn[3]-'0')*3 +(isbn[4]-'0')*4 + (isbn[6]-'0')*5 + (isbn[7]-'0')*6+ (isbn[8]-'0')*7 +(isbn[9]-'0')*8+ (isbn[10]-'0')*9;
	int v = verify % 11;
	int i, j;
	

	if(v == 10 && isbn[12] == 'X')
		cout<<"Right"<<endl;
	else if(v == 10 && isbn[12] != 'X')
	{
		for(i = 0; i <= 11; i++)
			cout<<isbn[i];
		cout<<"X"<<endl;
	}
	else if( v == isbn[12] - '0')
	{
		cout<<"Right"<<endl;
	}
	else
	{
		for(i = 0; i <= 11; i++)
			cout<<isbn[i];
		cout<<v<<endl;
	}
	
	
	
	
	
	return 0;
}
