
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
#include <cassert>

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
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

inline VS split(string s,char* tok){VS vs;char *pch;char *q= (char*)s.c_str();	pch=strtok(q," ");	while(pch !=NULL){vs.pb(string(pch));pch=strtok(NULL,tok);}return vs;}
inline int digitsIn(ll n){int ans=0;while(n){n/=10;ans++;}return ans;}

int v,e;
struct edge
{
	int f;
	int t;
	int w;
};
edge edges[201];
int  cmp(const void *a,const void *b)
{
	edge *e1=(edge*)a;
	edge *e2=(edge*)b;
	return e1->w - e2->w;
}


int parent[201];
int rank[201];
int getroot(int i)
{
	if(parent[i]!=i)parent[i]=getroot(parent[i]);
	return parent[i];
}
void Link(int x, int y) {
	if(rank[x]>rank[y])
		parent[y] = x;
	else {
		parent[x] = y;
		if(rank[x] == rank[y])
			rank[y] ++;
	}
}
int build(int ind)
{
	
	int ans=0;
	int mlen=0,gp1,gp2;
	for(int i=0;i<e && mlen <v-1;i++)
	{
		if(i==ind)continue;
		gp1=getroot(edges[i].t);
		gp2=getroot(edges[i].f);
		if(gp1!=gp2)
		{
			ans+=edges[i].w;
			Link(gp1,gp2);
			mlen++;
		}
	}
	if(mlen<(v-1))
	{
	//	cerr<<"-1 :"<<ind<<endl;
		return -1;
		
	}
	return ans;
	
}
int edgesTree[203];
int main()
{
	int kase=0;
	tests(tc)
	{
		scanf("%d%d",&v,&e);
		FOR(i,e)
		{
			scanf("%d%d%d",&edges[i].f,&edges[i].t,&edges[i].w);	
			edges[i].f--;
			edges[i].t--;		
		}
		
		qsort(edges,e,sizeof(edge),cmp);
		FOR(i,v){parent[i]=i;rank[i]=0;}
		int ans=0;
		int mlen=0;
		for(int i=0;i<e && mlen<v-1;i++)
		{
			int gp1=getroot(edges[i].f);
			int gp2=getroot(edges[i].t);
			if(gp1!=gp2)
			{
				//cerr<<"GP1 GP2 "<<gp1<<" "<<gp2<<" FOR IND "<<i<<endl;
				ans+=edges[i].w;
				Link(gp1,gp2);
				//edgesTree[i]=1;
				edgesTree[mlen]=i;
				mlen++;
			}
		}
		if(mlen<v-1)
		{
			cout<<"Case #"<<(++kase)<<" : "<<"No way"<<endl;
			continue;
		}
		
		int ans2=(1<<30),res;
		int f=1;
		FOR(i,mlen)
		{
			FOR(j,v){parent[j]=j;rank[j]=0;}
			res=build(edgesTree[i]);
			if(res==-1)continue;
			ans2=min(ans2,res);
			f=0;
			
		}
		
	//	cerr<<"err : MST AND SMST "<<ans<<" "<<ans2<<endl;
		if(f)
		{
			cout<<"Case #"<<(++kase)<<" : "<<"No second way"<<endl;
			continue;
		}
		else cout<<"Case #"<<(++kase)<<" : "<<ans2<<endl;
		
	
		
		
		
		
	}
}
