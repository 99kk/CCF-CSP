#include <iostream>
#include <math.h>
#include <set>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct node{
	int sum, prePath;
	node(){
		sum = 10e6+1; prePath = 0;
	}
}; 

struct crose{
	int isPath, des, len;
	crose(int i, int d, int l){
		isPath = i; des = d; len = l;
	}
	bool operator < (const crose &obj) const
	{
		return len < obj.len;
	}
};

set<crose> path[501];

int main(int argc, char** argv) {
	int n,m;
	cin>>n>>m;
	int t, a, b, c;
	int i, j;
	for(i = 0; i < m; i++)
	{
		cin>>t>>a>>b>>c;
		path[a].insert(crose(t, b, c));
		path[b].insert(crose(t, a, c));
	}
	
	node *opt = new node[n+1];
	opt[1].sum = 0;
	int tmp;
	bool flag = true;
	while(flag){
		flag = false;
		for(i = 1; i <= n; i++)
		{
			for(set<crose>::iterator it = path[i].begin(); it != path[i].end(); it++){
				if(it->isPath == 1){
					tmp = (opt[i].sum - opt[i].prePath * opt[i].prePath) + (opt[i].prePath+ it->len)*(opt[i].prePath+ it->len);
					if(tmp < opt[it->des].sum){
						opt[it->des].sum = tmp;
						opt[it->des].prePath = opt[i].prePath+ it->len;
						//cout<<i<<"-"<<it->des<<":"<<tmp<<endl;
						flag = true;
					}
				}
				else{
					tmp = opt[i].sum + it->len;
					if(tmp < opt[it->des].sum){
						opt[it->des].sum = tmp;
						opt[it->des].prePath = 0;
						//cout<<i<<"-"<<it->des<<":"<<tmp<<endl;
						flag = true;
					}
					
				}
			}
		}
		
		
	}

	
	cout<<opt[n].sum<<endl;
	
	
	
	
	
	return 0;
}
