
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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

using namespace std;
inline VS split(string s,char* tok){VS vs;char *pch;char *q= (char*)s.c_str();	pch=strtok(q," ");	while(pch !=NULL){vs.pb(string(pch));pch=strtok(NULL,tok);}return vs;}
inline int digitsIn(ll n){int ans=0;while(n){n/=10;ans++;}return ans;}
#define MAX 101
int ans[2][MAX];

int main()
{
	int s1[MAX],s2[MAX];
	int n1,n2;
	int kase=0;
	while(kase++,scanf("%d%d",&n1,&n2)!=EOF)
	{
		memset(ans,0,sizeof ans);
		if(n1==0 && n2==0) break;
		FOR(i,n1)scanf("%d",&s1[i]);
		FOR(i,n2)scanf("%d",&s2[i]);		
		
		int t=0;
		FORS(i,1,n1+1)
		{
			
			
			FORS(j,1,n2+1)
			{
				if(s1[i-1]==s2[j-1])
				{
					ans[1][j]=1+ans[0][j-1];
				}
				else
				{
					
					ans[1][j]=MAX2(ans[0][j],ans[1][j-1]);
					
				}
			}
			memcpy(ans[0],ans[1],sizeof ans[1]);
		}
		printf("Twin Towers #%d\n",kase);
		printf("Number of Tiles : %d\n\n",ans[1][n2]);
		
		
	}
}
