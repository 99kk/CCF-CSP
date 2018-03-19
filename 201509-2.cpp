#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int y, d;
	cin>>y>>d;
	int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool run = (y % 4 == 0 && y % 100 != 0)|| (y % 400 == 0);
	month[2] += run;
	for(int i = 1; i <= 12; i++)
	{
		if(d > month[i])
			d -= month[i];
		else
		{
			cout<<i<<endl<<d<<endl;
			return 0;
		}
	}
	
	return 0;
}
