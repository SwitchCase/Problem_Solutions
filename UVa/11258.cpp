
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
#define tests(tc) int tc;scanf("%d%*c",&tc);while(tc--)
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

uint maxm=(int)((1LL<<31));
ll ans,temp;
ll dp[205];
int n;
string s;
ll rec(int i)
{
	if(i==n)return 0;
	if(dp[i]!=-1)return dp[i];
	if(s[i]=='0')return dp[i]=rec(i+1);
	else
	{
		ll temp=0LL;
		ll ret=0LL;
		for(int k=1;k<=10 && i+k<=n;k++)
		{
			temp*=10;
			temp+= s[k+i-1]-'0';
			if(temp<maxm)
			ret=max(ret,temp+rec(k+i));
		}
		return dp[i]=ret;
	}
}
int main()
{
	char buff[205];
	
	tests(tc)
	{
		//cerr<<"MAXM "<<maxm<<endl;
		INIT(dp,-1);
		ans=0LL;
		cin.getline(buff,205);
		s=string(buff);
		n=s.size();
		
		
		/*cerr<<"------------------"<<endl;
		FOR(i,n+1)
		{
			FOR(j,n+1)
			{
				cerr<<dp[i][j]<<" ";
			}
			cerr<<endl;
		}
		cerr<<"------------------"<<endl;*/
		cout<<rec(0)<<endl;
	}
}
