
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

int arr[11][101];
ll dp[11][101];
//string path[11][101];
int r,c;
int dir[]={-1,0,1};
int main()
{
	while(scanf("%d%d",&r,&c)!=EOF)
	{
		INIT(arr,0);
		FOR(i,r)FOR(j,c)dp[i][j]=100000000000000LL;
		FOR(i,r)
			FOR(j,c)scanf("%d",&arr[i][j]);
		FOR(j,r)dp[j][c-1]=arr[j][c-1];
		for(int cc=c-2;cc>=0;cc--)
		{
			int curr=cc;
			FOR(rr,r)
			{
				FOR(k,3)
				{
					ll t= arr[rr][curr]+ dp[(rr + dir[k] + r)%r][cc+1];
					dp[rr][curr] = MIN2( t,dp[rr][curr] );
				}
			}
		}
		ll ans=1000000000000LL;
		int ind=-1;
		FOR(i,r)
		{
			if(ans>dp[i][0]){ans=dp[i][0];ind=i;}
		}
		int final;
		
		final=ans;
		int curr=ind;
		cout<<(ind+1);
		FORS(cc,1,c)
		{
			ans=1000000000000LL;
			curr=100000000;
			FOR(k,3)
			{
				if(ans >= dp[(ind+dir[k]+r)%r][cc])
				{
					if(ans == dp[(ind+dir[k]+r)%r][cc] && curr>(ind+dir[k]+r)%r)curr=(ind+dir[k]+r)%r;
					else if(ans>dp[(ind+dir[k]+r)%r][cc]) curr=(ind+dir[k]+r)%r;
					ans=dp[(ind+dir[k]+r)%r][cc];
					
					
				}
			}
			cout<<" "<<(curr+1);
			ind=curr;
		}
		cout<<endl;
		cout<<final<<endl;
	}
}
