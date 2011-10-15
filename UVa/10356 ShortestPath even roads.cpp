
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
typedef vector<ii> vii;
typedef vector<vii> vvii;
vvii Graph;
int v,e;
int mat[501][501];
struct item
{
	public:
	int y;
	int w;
	int val;
	item(int a,int b,int c)
	{
		y=a;
		w=b;
		val=c;
	}
	item(ii p,int c)
	{
		y=p.first;
		w=p.second;
		val=c;
	}
	
	bool operator<(const item &other)const
	{
		if( (*this).w != other.w)return (*this).w < other.w;
		else if((*this).y!=other.y)return (*this).y < other.y;
		else return (*this).val < other.val;
	}
};

int D[502][2];
set<item> Q;
//item Q[501*499 +1];
int main()
{
	int x,y,w;
	int kase=0;
	int r,l;
	
	while(scanf("%d%d",&v,&e)!=EOF)
	{
		kase++;
		Graph.clear();
		FOR(i,v)
		{
			vii temp;
			Graph.pb(temp);
		}
		FOR(i,e)
		{
			scanf("%d%d%d",&x,&y,&w);
			Graph[x].pb(ii(y,w));
			Graph[y].pb(ii(x,w));
		}
		r=l=0;

		FOR(i,502)
		{
			D[i][0]=99999999;
			D[i][1]=99999999;
		}
		D[0][0]=0;
		//D[0][1]=0;
		//cerr<<" DONE 1 "<<endl;
		
	Q.insert(item(ii(0,0),0));
		while(!Q.empty())
		{
			item top=*Q.begin();
			Q.erase(Q.begin());
			int vv=top.y;int cc=top.val;
			FOR(i,Graph[vv].size())
			{
				int cost=Graph[vv][i].second;
				int v2=Graph[vv][i].first;
				if(D[v2][!cc] > D[vv][cc]+cost)
				{
					if(D[v2][(!cc)]!=99999999)
					{
						set<item>::iterator it=Q.find(item(v2,D[v2][!cc],!cc));
						if(it!=Q.end())
						Q.erase(it);
						//else cerr<<"SDASDSD"<<endl;
					}
					D[v2][!cc]=D[vv][cc]+cost;
					Q.insert(item(v2,D[v2][!cc],!cc));
				}
			}
		}
		
		cout<<"Set #"<<kase<<endl;
		if(D[v-1][0]<99999999)
		{
			cout<<D[v-1][0]<<endl;
		}
		else
		{
			cout<<"?"<<endl;
		}
		
	}	
}
