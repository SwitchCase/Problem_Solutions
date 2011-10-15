
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

int n,p,q,s;
int length[101];
vector<VI> graph;
typedef pair<int,int> ii;
queue<ii> Q;

int main()
{
	int kase=0,te;
	while(1)
	{
		INIT(length,0);
		scanf("%d",&n);
		graph.clear();
		if(n==0)return 0;
		scanf("%d",&s);
		s--;
		
		FOR(i,n)
		{
			VI temp;
			graph.pb(temp);
		}
		scanf("%d %d",&p,&q);
		while(p!=0 && q!=0)
		{
			graph[p-1].pb(q-1);
			scanf("%d%d",&p,&q);
		}
		
		Q.push(ii(s,0));
		int ansLen=0,ansInd=0;

		while(!Q.empty())
		{
			ii temp=Q.front();
			Q.pop();
			FOR(it,graph[temp.first].size())
			{
				te=graph[temp.first][it];
				if(length[te]<(temp.second+1))
				{
					length[te]=temp.second+1;
					Q.push(ii(te,length[te]));
					if(ansLen==length[te] && te<ansInd)
					{
						ansInd=te;
					}
					if(ansLen<length[te])
					{
						ansLen=length[te];
						ansInd=te;
					}
					
				}
			}
			
		}
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",(++kase),s+1,ansLen,(ansInd+1));
	}	
	
}
