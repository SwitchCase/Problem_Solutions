
// <-------------------[sWitCHcAsE]---------------------->

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>

#define FOR(i,a) for(int i=0;i<a;i++)
#define FORS(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a) for(int i=a;i>=0;i--)
#define foreach(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define MAX2(a,b) (a)<(b)?(b):(a)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define LEN(s) strlen(s)
#define tests(tc) int tc;scanf("%d",&tc);while(tc--)
#define TEN(n) (long long)pow(10LL,n)
#define bits __builtin_popcount
#define INIT(arr,val) memset(arr,val,sizeof arr)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

using namespace std;
inline VS split(string s,char* tok){VS vs;char *pch;char *q= (char*)s.c_str();	pch=strtok(q," ");	while(pch !=NULL){vs.pb(string(pch));pch=strtok(NULL,tok);}return vs;}
inline int digitsIn(ll n){int ans=0;while(n){n/=10;ans++;}return ans;}

struct edge
{
	int f;
	int t;
	int w;
	
};

edge g[512];
edge B[512];
int added[17];
int arr[17][17];
void sort(int n)
{
	int C[11];
	FOR(i,11)C[i]=0;
	FOR(i,n)C[g[n].w]=C[g[n].w]=1;
	for(int i=1;i<11;i++)C[i]=C[i]+C[i-1];
	FORR(i,n)
	{
		B[C[g[i].w]]=g[i];
		C[g[i].w]--;
	}
}
int main()
{
	tests(tc)
	{
		int n;
		scanf("%d",&n);
		FOR(i,n)
		FOR(j,n)scanf("%d",&arr[i][j]);
		int c=0;
		FOR(i,n)
		FOR(j,n)
		{
			edge e;
			e.f=i;e.t=j;e.w=arr[i][j];
			g[c++]=e;			
		}
		int ans=10000001;
		int t=0;
		sort(c);
		memset(added,0,sizeof added);
			FOR(i,c)
			{
				if(added[B[i].t]==0 || added[B[i].f]==0)
				{
					t+=B[i].w;
					added[B[i].t]=1;
					added[B[i].f]=1;
				}
			}
			
		
		cout<<t<<endl;
	}

}
