// <-------------------[sWitCHcAsE]---------------------->
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<vector>
#include<map>
#include<cstring>
#include<cassert>
#include<queue>

#define FOR(i,n) for(i=0;i<n;i++)
#define FORS(i,a,n) for(i=a;i<n;i++)
#define ERR(x) cerr<<#x<<" "<<x<<endl
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
typedef long double ld;

class T{
	public:
	int a;
	int *p;
	
};

 
int main(int argc,char** args)
{
	T t;
	
	t.a=10;
		t.p=(int*)malloc(2*sizeof (int));
		t.p[0]=101;
		t.p[1]=12;
	t.p[0]=12;
	T tt=T(t);
	tt.p[0]=10;
	tt.a=100;
	cout<<t.p[0]<<" "<<tt.p[0]<<endl;
	cout<<t.a<<" "<<tt.a<<endl;
}
