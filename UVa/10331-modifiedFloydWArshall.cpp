
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
#define bits __builtin_popcounter
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
	int u,v;
	int w;
};
int V,E,tE;
int graph[101][101]={0};
int used[101][101]={0};
typedef pair<int,int> ii;
edge edges[10001];
int paths[101][101];
int counter[10001];
int main()
{
	int x,y,w;
	int temp,temp2;
	vector<ii> most;
	VI ans;
	int c;
	while(scanf("%d%d",&V,&E)!=EOF)
	{
		tE=0;
		c=0;
		FOR(i,V){FOR(j,V){graph[i][j]=987654321;}graph[i][i]=0;}
		
		ans.clear();
		INIT(counter,0);
		INIT(paths,0);
		INIT(used,0);
		
		FOR(i,E)
		{
			scanf("%d%d%d",&x,&y,&w);
			x--;y--;
			if(graph[x][y]>w){
				graph[x][y]=w;
				graph[y][x]=w;
			}
			edges[i].u=x;
			edges[i].v=y;
			edges[i].w=w;
			used[x][y]=x;
			used[y][x]=y;
		}
		FOR(k,V)
		{
			FOR(i,V)
			{
				FOR(j,V)
				{
				
					temp=graph[i][j];
					temp2=graph[i][k]+graph[k][j];
					if(temp2<temp)
					{
						used[i][j]=used[k][j];
					}
					graph[i][j]=min(temp,temp2);
				}
			}
		}
		int maxm=0;
		int s,f,ff;
		FOR(i,V)
		{
			FORS(j,i+1,V)
			{
				FOR(k,E)
				{
					if(edges[k].w > graph[edges[k].u][edges[k].v])continue;
					if(graph[i][edges[k].u] + graph[edges[k].v][j] + edges[k].w ==graph[i][j] ||
					graph[i][edges[k].v] + graph[edges[k].u][j] + edges[k].w ==graph[i][j])
					{
						counter[k]++;
					}
					if(maxm<counter[k])maxm=counter[k];
				}
			}
		}
		FOR(i,E)
		{
			if(counter[i]==maxm)ans.pb(i+1);
		}
		
		sort(ans.begin(),ans.end());
		FOR(i,ans.size())
		{
			cout<<ans[i];
			if(i!=ans.size()-1)cout<<" ";
		}
		cout<<endl;
		
		
	}	
}
