
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
typedef pair<int,int> ii;
int v,e;
vector<ii> adj[1001];
int n,m;
int visited[1001];
int minm;
int found=0;
#define GRAY 999999998
#define BLACK 999999999
int check[1001];
int chk=0;

int dfs(int u)
{
	//cerr<<"DFS "<<u<<endl;
	//cerr<<"VISITED "<<u<<"  "<<visited[u]<<endl;
	//if(found)return -1;
	int maxm=1000000,t;
	
	if(visited[u]==GRAY)
	{
		check[chk++]=u;
		//cerr<<"IS GRAY : "<<u<<endl;
		return 0;
	}
	else if(visited[u]!=BLACK)
	{
	//	cerr<<" IS BLACK "<<endl;
		return visited[u];
	}
	visited[u]=GRAY;
	FOR(i,adj[u].size())
	{
		
		t= adj[u][i].second + dfs(adj[u][i].first);
		if(t<maxm)maxm=t;
	}
//	cerr<<"DFS "<<u<<"  maxm: "<<maxm<<endl;
	//if(maxm<0)found++;
	return visited[u]=maxm;
}
int main()
{
	int x,y,c,ans;
	FOR(i,1001)visited[i]=BLACK;
	tests(tc)
	{
		//INIT(visited,0);
		found=0;
		chk=0;
		
		scanf("%d%d",&n,&m);
		FOR(i,m)
		{
			scanf("%d%d%d",&x,&y,&c);
			//c+=1001;
			adj[x].pb(ii(y,c));
		}
		ans=dfs(0);
		//cerr<<"ANS :"<<ans<<endl;
		FOR(i,chk)
		{
			//cerr<<"IN CHECK "<<check[i]<<endl;
			if(visited[check[i]]<0){found=1;break;}
			else found=0;
		}
		if(found)cout<<"possible"<<endl;
		else cout<<"not possible"<<endl;	
			
		FOR(i,1001)
		{
			visited[i]=BLACK;
			adj[i].clear();
		}
		//cerr<<"---------------------------------"<<endl;
	}
	
}
