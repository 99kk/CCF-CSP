#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int t;
	cin>>t;
	if(t <= 3500) cout<<t<<endl;
	else if(t <= 4955) cout<<3500+(t-3500)*100/97<<endl;
	else if(t <= 7655) cout<<5000+ (t-4955)*10/9<<endl;
	else if(t <= 11255) cout<<8000+ (t-7655)*5/4<<endl;
	else if(t <= 30755) cout<<12500+ (t-11255)*4/3<<endl;
	else if(t <= 44755) cout<<38500+ (t-30755)*10/7<<endl;
	else if(t <= 61005) cout<<58500 +(t-44755)*100/65<<endl;
	else cout<<83500+ (t-61005)*100/55<<endl;
	
	
	
	return 0;
}
