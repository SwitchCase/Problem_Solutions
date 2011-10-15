
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

int m,n;
int arr[1001][1001]={0};
int visited[1001][1001]={0};
int isl=1;

int dirr[]={0,0,-1,1};
int dirc[]={-1,1,0,0};
int dfs(int i,int j)
{
	if(i>=m || j>=n)return 0;
	if(i<0 || j<0)return 0;
	if(visited[i][j])return 0;
	visited[i][j]=isl;
	if(arr[i][j]!=1)return 0;
	return 1+ dfs(i,j+1)+dfs(i,j-1)+dfs(i-1,j)+dfs(i+1,j);
}
int main()
{
	char c;
	scanf("%d%d",&m,&n);
	scanf("%*c");
	FOR(i,m)
	{
		FOR(j,n)
		{
			scanf("%c",&c);
			if(c=='x')arr[i][j]=1;
			//cout<<"GOT A "<<c<<" "<<arr[i][j]<<endl;
		}
		scanf("%*c");
	}
	int ans=0;
	/*FOR(i,m)
	{
		FOR(j,n)cerr<<arr[i][j]<<" ";
		cerr<<endl;
	}*/
	FOR(i,m)
	{
		FOR(j,n)
		{
			if(arr[i][j]==1 && !visited[i][j])
			{
				int t=dfs(i,j);
				if(t>ans)ans=t;
				if(t!=0)isl++;
			}
			
		}
	}
	cout<<(isl-1)<<" "<<ans<<endl;
}
