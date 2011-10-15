
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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

using namespace std;
inline VS split(string s,char* tok){VS vs;char *pch;char *q= (char*)s.c_str();	pch=strtok(q," ");	while(pch !=NULL){vs.pb(string(pch));pch=strtok(NULL,tok);}return vs;}
inline int digitsIn(ll n){int ans=0;while(n){n/=10;ans++;}return ans;}

int dp[3001][2]={0};
int sumof[3001];

int sumin(int n)
{
	int ans=0;
	while(n)
	{
		ans+=n%10;
		n/=10;
	}
	return ans;
}
void dosumof()
{
	FOR(i,3001)
	{
		sumof[i]=sumin(i);
	}
	
}
int dfs(int m)
{
	assert(m<3001);
	if(dp[m][0]==m)return 1;
	if(dp[m][1]==0)
	{
		return dp[m][1]=1+dfs(dp[m][0]);
	}
	else return dp[m][1];
}
void preprocess()
{
	dosumof();
	FORS(i,1,3001)
	{
		int sum=0;
		//cerr<<"FACTORS OF "<<i<<" ";
		for(int j=1;j*j<=i;j++)
		{
			if(i%j==0)
			{
				//cerr<<j<<" ";
				sum+= sumof[j];
				if(j*j !=i)
				{
					//cerr<<i/j<<" ";
					sum+=sumof[i/j];
				}
			}
			
		}
		//cerr<<endl;
		dp[i][0]=sum;
	}
	//cerr<<"DOING DFS \n";
	FOR(i,3001)
	{
		if(dp[i][1]==0)dp[i][1]=dfs(i);
	}
}

int main()
{
	preprocess();
	int m,n;
	int kase=0;
	while(kase++,scanf("%d%d",&m,&n)!=EOF)
	{
		printf("Input%d: %d %d\n",kase,m,n);
		if(m>n)swap(m,n);
		int maxi=m,maxv=0;
		FORS(i,m,n+1)
		{
			if(maxv<dp[i][1])
			{
				maxv=dp[i][1];
				maxi=i;
			}
		}
		printf("Output%d:",kase);
		while(1)
		{
			printf(" %d",maxi);
			if(maxi==dp[maxi][0])break;
			maxi=dp[maxi][0];
		}
		printf("\n");
	}
}
