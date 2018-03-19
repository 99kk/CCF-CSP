#include <iostream>
#include <set>
using namespace std;

struct edge{
	int u, v, w;
	edge(int uu, int vv, int ww){u = uu, v = vv; w = ww;
	}
	bool operator < (const edge &obj) const{
		return w <= obj.w;
	}
};

set<edge> s;

int v[1001];

class UF{
	int length;
public:
	UF(int n){
		length = n; 
		for(int i = 0; i <= n; i++)
			v[i] = i;
	}
	
	int Find(int x)
	{
		if(x == v[x]) return x;
		else
			return v[x] = Find(v[x]);
	}
	
	bool Union(int x, int y)
	{
		x = Find(x); y = Find(y);
		if(x == y)	return false;
		else {
			v[x] = y; return true;
		}
	}
};



int main(int argc, char** argv) {
	int n, m;
	cin>>n>>m;
	
	int i, j;
	int a, b, c;
	for(i = 1; i <= m; i++)
	{
		cin>>a>>b>>c;
		s.insert(edge(a,b,c));
	}
	int sum = 0;
	UF uf(n);
	int count = 0;
	for(set<edge>::iterator it = s.begin(); it != s.end(); it++)
	{
		a = it->u; 
		b = it->v; 
		c = it->w;
		if( uf.Find(a) != uf.Find(b) ){
			uf.Union(a, b);
			sum += c;
			//cout<<a<<" "<<b<<" "<<c<<endl;
			count++;
			if(count == n-1) break;
		}
		
		
	}
	cout<<sum<<endl;
	return 0;
}
