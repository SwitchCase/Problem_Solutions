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

#define MAX 1000001
#define MAXV 1000000001
int main(int argc,char** args)
{
	int i;
	int n=MAX - 1;
	int m=250000;
	int c= rand()%1000000001;
	cout<<n<<" "<<m<<" "<<c<<endl;
	int u,v,k;
	FOR(i,m) {
		int typ=rand()%(17*13);
		if(typ%5==0) {
			u=rand()%(n+1);
			if(u==0)u++;
			cout<<"Q "<<u<<endl;
		}
		else {
			u= rand()%n;
			v=rand()%n;
			k=rand()%MAXV;
			u++;v++;
			cout<<"S "<<u<<" "<<v<<" "<<k<<endl;
		}
	
	}
 	
 	
}
