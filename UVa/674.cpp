
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

int dp[7490][6]={0};

void preprocess()
{
	int coins[]={0,1,5,10,25,50};
	FOR(i,6)dp[0][i]=1;
	dp[1][1]=1;
	dp[1][0]=1;
	FORS(i,2,7490)
	{
		int temp=0;
		FORR(j,5)
		{
			if(j==0)break;
			if(i>coins[j])
			FORS(k,1,j+1)
			{
				dp[i][j]+=dp[i-coins[j]][k];
			}
			else if(i==coins[j])dp[i][j]=1;
			else continue;
			temp+=dp[i][j];
		}
		dp[i][0]=temp;
	}
	
}
int main()
{
	preprocess();
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",dp[n][0]);
	}
}
