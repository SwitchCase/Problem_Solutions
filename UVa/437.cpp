
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

struct dim
{	
	ll h;
	ll w;
	ll d;
};

dim inp[31];
dim arr[31*3 +1];
ll dp[31*3 +1];
int n;

bool cmp(dim a,dim b)
{
	if(a.w==b.w)return a.d<b.d;
	return a.w < b.w;
}
void construct()
{
	int c=0;
	int curr;
	FOR(i,n)
	{
		
		arr[3*i].h=inp[i].h;arr[3*i].w=max(inp[i].w,inp[i].d);arr[3*i].d=min(inp[i].w,inp[i].d);
		//temp=arr[3*i +1];
		arr[3*i +1].h=inp[i].w;arr[3*i +1].w=max(inp[i].h,inp[i].d);arr[3*i +1].d=min(inp[i].h,inp[i].d);
		//temp=arr[3*i +2];
		arr[3*i +2].h=inp[i].d;arr[3*i +2].w=max(inp[i].w,inp[i].h);arr[3*i +2].d=min(inp[i].w,inp[i].h);
	}
}

int main()
{
	int tc=1;
	while(1)
	{
		scanf("%d",&n);
		if(!n)break;
		FOR(i,n)
		{
			scanf("%lld %lld %lld",&inp[i].h,&inp[i].w,&inp[i].d);
			
		}
		construct();
		
		sort(arr,arr+(3*n),cmp);
		/*
		cerr<<"********************************************"<<endl;
		FOR(i,3*n)
		{
			cout<<arr[i].h<<" "<<arr[i].w<<" "<<arr[i].d<<endl;
		}
		cerr<<"*********************************************"<<endl;*/
		n=3*n;
		ll ans=0LL;
		
		FOR(i,n)
		{
			dp[i]=arr[i].h;
			FOR(j,i)
			{
				if(arr[i].w > arr[j].w && arr[i].d > arr[j].d)
				dp[i]=max(dp[i],dp[j]+arr[i].h);
			}
		}
		FOR(i,n)if(ans<dp[i])ans=dp[i];
		printf("Case %d: maximum height = %lld\n",tc,ans);
		tc++;
		//cerr<<"---------------------------------------"<<endl;
	}
}
