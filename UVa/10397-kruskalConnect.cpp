
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
typedef pair<double,double> ii;
int parent[752];
int rank[752];
int n,m;
struct edge
{
	int v,u;
	double w;
};
edge edges[1001];
ii builds[751];
edge alledges[751*750 +2];
int F[752][752];

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
void Make()
{
	FOR(i,n)
	{
		parent[i]=i;
		rank[i]=0;
	}
}


double getd(int a,int b)
{
	double p=builds[a].first - builds[b].first;
	double q=builds[a].second-builds[b].second;
	double ans=sqrt(1.0*p*p + 1.0*q*q);
	return ans;
}


int cmp(edge a,edge b)
{
	return a.w < b.w;
}
int main()
{
	int x,y;
	double dx,dy;
	while(scanf("%d",&n)!=EOF)
	{
		FOR(i,n)
		{
			scanf("%lf%lf",&dx,&dy);
			builds[i]=ii(dx,dy);
		}
		scanf("%d",&m);
		Make();
		FOR(i,m)
		{
			scanf("%d%d",&x,&y);
			x--;y--;
			F[x][y]=1;
			double w=getd(x,y);
		//	cerr<<"DIST b/w "<<x<<" "<<y<<" "<<w<<endl;
			edge temp;
			temp.u=x;temp.v=y;temp.w=w;
			edges[i]=temp;
			x=getroot(temp.u);
			y=getroot(temp.v);
			if(x!=y)Link(x,y);
			
		}
		
		int c=0;
		FOR(i,n-1)
		{
			FORS(j,i+1,n)
			{
				if(F[i][j]==1){F[i][j]=0;continue;}
				double tw=getd(i,j);
				alledges[c].u=i;
				alledges[c].v=j;
				alledges[c].w=tw;
				c++;
			}
		}
		sort(alledges,alledges+c,cmp);
	/*cerr<<"PRINT EDGES"<<endl;
		FOR(i,c)
		{
			cerr<<alledges[i].w<<endl;
		}
		cerr<<"************"<<endl;
		*/
		double ans=0;
		FOR(i,c)
		{
			x=getroot(alledges[i].u);
			y=getroot(alledges[i].v);
			if(x!=y)	
			{
			//	cerr<<"ADDING ("<<alledges[i].u<<", "<<alledges[i].v<<" )"<<endl;
				ans+=alledges[i].w;
				Link(x,y);
			}
		}
		printf("%.2lf\n",ans);
	}
}
