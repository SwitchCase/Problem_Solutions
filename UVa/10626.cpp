
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

#define INF 10000

int dp[161][211][51];
int C,N1,N5,N10;
int M;
int f(int c,int n5,int n10)
{	
	//cout<<"CALLED "<<c<<" "<<n5<<" "<<n10<<" ";
	if(n5<0 || n10<0){cerr<<"INF : "<<c<<" "<<n5<<" "<<n10<<endl;return INF;}
	
	int n1=M-(C-c)*8-5*n5-10*n10;
	//if(n1<0)n1*=-1;
	//cout<<n1<<endl;
	
	if(n1<0){ cerr<<"INF due to n1"<<c<<" "<<n5<<" "<<n10<<endl;return INF;}
	if(c==0)return 0;
	if(dp[c][n5][n10]!=-1)return dp[c][n5][n10];
	int &ans=dp[c][n5][n10];
	ans=INF;
	
	if(n1>=8)ans=min(ans,f(c-1,n5,n10) + 8);
	if(n1>=3 && n5>=1)ans=min(ans,f(c-1,n5-1,n10)+4);
	if(n10>=1)ans=min(ans,f(c-1,n5,n10-1)+1);
	if(n5>=2)ans=min(ans,f(c-1,n5-2,n10)+2);
	if(n10>=1 && n1>=3)ans=min(ans,f(c-1,n5+1,n10-1)+4);
	 ans=(ans==INF?0:ans);
	 if(ans==INF)cerr<<c<<" "<<n1<<" "<<n5<<" "<<n10<<endl;
	 return dp[c][n5][n10]=ans;
	
}

int main()
{
	tests(tc)
	{
		scanf("%d%d%d%d",&C,&N1,&N5,&N10);
		INIT(dp,-1);
		M=N1+5*N5+10*N10;
		int ans=INF;
		int cal=0;//just to check if calls are being made
		if(N1>=8){ans=min(ans,f(C-1,N5,N10) + 8);cal+=1;}
		if(N1>=3 && N5>=1){ans=min(ans,f(C-1,N5-1,N10)+4);cal|=(2);}
		if(N10>=1){ans=min(ans,f(C-1,N5,N10-1)+1);cal|=4;}
		if(N5>=2){ans=min(ans,f(C-1,N5-2,N10)+2);cal|=8;}
		if(N10>=1 && N1>=3){ans=min(ans,f(C-1,N5+1,N10-1)+4);cal|=16;}
		cout<<ans<<endl;
		//cerr<<cal<<endl;
		
		//cout<<f(C,N5,N10)<<endl;
	}
}
