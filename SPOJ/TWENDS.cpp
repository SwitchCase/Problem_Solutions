
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
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define MAX2(a,b) (a)<(b)?(b):(a)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define LEN(s) strlen(s)
#define tests(tc) int tc;scanf("%d",&tc);while(tc--)
#define TEN(n) (long long)pow(10LL,n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

inline int digitsIn(ll n){int ans=0;while(n){n/=10;ans++;}return ans;}
using namespace std;

int dp[2001][2001];
int n;
int q[2001];
int fun(int i,int j,int day)
{
	if(i<=j)
	{
		if(day%2)
		{
			int ans=0;
			if(i+1<n && dp[i+1][j])ans+= q[i]+ dp[i+1][j];
			else if( i+1<n) ans+= q[i]+ fun(i+1,j,day+1);
			if(j-1>=0 && dp[i][j-1])ans=MAX2(ans,q[j] + dp[i][j-1]);
			else if(j-1>=0)
			{
				int temp=fun(i,j-1,day+1);
				ans=MAX2(ans,q[j] + temp);
			}	
			return dp[i][j]=ans;
		}
		else 
		{
			int curr=0,iorj=0;
			curr=q[i];
			if( curr< q[j])
			{
				iorj=1;
				curr=q[j];
			}
			return dp[i][j]=fun(i+!iorj , j- iorj,day+1);			
		}
	}
	else return 0;
}


int main()
{
	int g=1;	
	while(1)
	{	
		scanf("%d",&n);
		if(n==0)break;
		memset(dp,0,sizeof dp);
		FOR(i,n)scanf("%d",&q[i]);
		int ans=fun(0,n-1,1);
		int diff=0;
		FOR(i,n)diff+=q[i];
		diff=diff-ans;
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",g++,ans-diff);
	}
	
}
