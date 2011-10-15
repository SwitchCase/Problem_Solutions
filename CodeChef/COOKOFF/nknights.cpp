
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
inline VS split(string s,char* tok){VS vs;char *pch;char *q= (char*)s.c_str();	pch=strtok(q," ");	while(pch !=NULL){vs.pb(string(pch));pch=strtok(NULL,tok);}return vs;}
inline int digitsIn(ll n){int ans=0;while(n){n/=10;ans++;}return ans;}
typedef pair<int,int> ii;

int n,m;
int arr[55][55];

inline bool inside(int r,int c)
{
	if(r>=0 && r<n && c>=0 && c<m)return true;
	return false;
}
map<int[][],n> dp;

int best;
int solve(int currM[][])

	if(dp.find(currM)!=dp.end())return dp[currM];
	dp[currM]=1;
	int ret;
	int kn=0,emp;
	FOR(i,n)
	{
		FOR(j,m)
		{
			if(arr[i][j]==0 && inp[i][j]!='#')
			{
				for(int dr=-2;dr<=2;dr++)
				{
					for(int dc=-2;dc<=2;dc++)
					{
						if(abs(dc*dr)==2)
						{
							int cr=i+dr;
							int cc=j+dc;
							if(inside(cr,cc))
							{
								if(arr[cr][cc]!=1 && inp[cr][cc]!='#')
								{
									emp=1;
									arr[cr][cc]=1;
									ret=max(ret,solve(arr[cr][cc]));
									arr[cr][cc]=0;
								}
							}
						}
					}
				}
			}
			else if(arr[i][j]==1)kn++; 
		}
	}
	if(ret!=0)
	{
		return ret;
	}
	else if(emp==0)
	{
		return kn;
	}
}


struct pos{
	int w;
	int p;
};

int main()
{
	int T;scanf("%d",&T);
	char inp[55][55];
	int weights[55][55];	
	VI non,avail;
	
	while(T--)
	{
		non.clear();
		avail.clear();
		memset(weights,0,sizeof weights);
		scanf("%d %d\n",&n,&m);
		FOR(i,n)
		{
			FOR(j,m)
			{
				scanf("%c",&inp[i][j]);
				if(inp[i][j]=='#')non.pb(m*i +j);
				
			}
			scanf("%*c");
		}
		FOR(i,n)
		{
			FOR(j,m)
			{
				printf("%c",inp[i][j]);
			}
			printf("\n");
		}
		int nn=non.size();
		int cr,cc;
		
		FOR(i,nn)
		{
			for(dr=-2;dr<=2;dr++)
			{
				for(dc=-2;dc<=2;dc++)
				{
					if(abs(dc*dr)==2)
					{
						cr=non[i]/m +dr;
						cc=non[i]%m +dc;
						if(inside(cr,cc))
						{
							weights[cr][cc]+=1;
							if(weights[cr][cc]==1)avail.pb(cr*m +cc);
						}		
					}
				}
			}
		}
		FOR(i,avail.size())
		{
			int t=avail[i];
			arr[t/m][t%m]=1;
		}
		//check for bad places.
		
		
		
	}
}
