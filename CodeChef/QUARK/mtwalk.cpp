
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

int n;
char  mapp[21][201];
char seq="/\\_";
int visited[21][201][2];

int dfs(int r,int c, int h)
{
	if(mapp[r][c]==' ')return 0;
	if(visited[r][c][0]!=-1)return visited[r][c][0];
	if(mapp[r][c]=='/')
	{
		visited[r][c][0]=dfs(r-1,c+1,h+1);
		visited[r][c][1]=h+1;
		
	}
}
int main()
{
	scanf("%d%*c",&n);
	//scanf("%*s");
	FOR(i,n+1)
	{
		if(i==0)cin.getline(mapp[0],201);
		cin.getline(mapp[i-1],201);
		cout<<": "<<mapp[i-1]<<endl;
	}
	int max=0;
	FOR(i,n)
	{
		FOR(j,strlen(mapp[i]))
		{
			int t=dfs(i,j,i);
			if(t>max_max=t;
		}
	}
	
	
}
