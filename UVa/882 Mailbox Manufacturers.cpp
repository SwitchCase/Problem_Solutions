
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


int dp[102][102][12];
int m,k;

int sumof(int a,int b)
{
	if(a>b)swap(a,b);
	int p1=b*(b-1)/2;
	int p2=(a)*(a+1)/2;
	return p1-p2;
}

int f(int lo,int hi,int b)
{
	if(b==0)return 0;
	if(hi-lo<=1)return 0;
	int &v= dp[lo][hi][b];
	if(v!=-1)return v;
	v=987654321;
	for(int s=lo+1;s<hi;s++)
	{
		v = min(v,s+ max(f(lo,s,b-1), f(s,hi,b)));
	}
	return v;
}

void preprocess()
{
	int m=100;	
	int k=10;
	FOR(i,m+2)
	{
		FORS(j,i+1,m+2)
		{
			dp[i][j][1]=sumof(i,j);
		}
	}
		
		FOR(l,m+2)
		{
			FORS(boxes,2,k+1)
			{
				FOR(s,m-l+2)
				{
					if(l<=1)
					{
						//cerr<<s<<" "<<(s+l)<<endl;
						dp[s][s+l][boxes]=0;continue;
					}
					dp[s][s+l][boxes]=987654321;
					FORS(x,s+1,s+l)
					{
						dp[s][s+l][boxes]= min(dp[s][s+l][boxes], x+max(dp[s][x][boxes-1], dp[x][s+l][boxes]));
					}
				}
			}
		}

}
int main()
{
	INIT(dp,-1);
	preprocess();
	tests(tc)
	{
		scanf("%d%d",&k,&m);
		
		//FOR(i,m+1)FOR(j,m+1)FOR(l,k+1)dp[i][j][l]=987654321;
		cout<<dp[0][m+1][k]<<endl;
		//cout<<f(0,m+1,k)<<endl;
		
	}
}
