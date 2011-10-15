
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


int dofor(int i,int j)
{
	if(i==0 && j==0)return 0;
	if(i==0 || j==0)return 1;
	if(i==j)return 1;
	int ans1=dofor(i-min(i,j),j-min(i,j));	
	if(ans1==0)return 1;
	//ans1=doFor(
	
}

int row[10005]={0},col[10005]={0};
int fr,fc;
int main()
{
	row[0]=0;col[0]=0;
	int x=1,y=2;
	int curr=1;
	fr=0;fc=0;
	while(curr<=10000)
	{
		//col
		int te=fr;
		while(row[te]!=0 && te<10005)
		{
			te++;
		}
		row[te]=curr+te;
		if(curr+te<10005)col[curr+te]=te;
		if(te+1==fr)fr++;
		//row
		te=fc;
		while(col[te]!=0 && te<10005)
		{
			te++;
		}
		col[te]=curr+te;
		if(curr+te<10005)row[curr+te]=te;
		if(te+1==fc)fc++;
		curr++;
	}
	tests(tc)
	{
		
		scanf("%d%d",&x,&y);
		if(x==y || x==0 || y==0)printf("PLAY\n");
		else if(row[x]!=y )printf("PLAY\n");
		else printf("CHANGE\n");
		
		
	}
}
