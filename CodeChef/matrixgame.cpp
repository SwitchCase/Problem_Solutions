
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

int mat[51][51];
int val[51][51];
int n,m;
int main()
{
	tests(tc)
	{
		scanf("%d%d",&n,&m);
		FOR(i,n)
		{
			FOR(j,m)scanf("%d",&mat[i][j]);
		}
		
		
		FOR(i,n)val[i][m-1]=0;
		
		FOR(i,n)
		{
			for(int j=m-2;j>=0;j--)
			{
				if(mat[i][j]==1)
				{
					val[i][j]=(val[i][j+1]==1?0:1);
				}
				else
				{
					val[i][j]=1;
				}
			}
		}
		int ans=0;
		int turn=m%2;
		/*
		for(int i=0;i<n;i++)
		{
			if(turn && i!=0)val[i][0]=!val[i][0];
			ans^=val[i][0];
			
			
		}*/
		ans=val[0][0];
		FOR(i,n)FOR(j,m)if(i==j && i==0)continue;else ans^=val[i][j];
		if(ans==0)printf("FIRST\n");
		else printf("SECOND\n");
	
	}
}
