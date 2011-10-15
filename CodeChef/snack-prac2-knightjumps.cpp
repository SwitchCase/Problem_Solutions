
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
struct state
{
	int moves;
	ii pos;
	state(ii curr,int move)
	{
		moves=move;
		pos=curr;
	}
};
queue<state> q;
int arr[1001][1001]={0};
int visited[1001][1001]={0};
int dirr[]={1,1,-1,-1,2,2,-2,-2};
int dirc[]={2,-2,2,-2,1,-1,1,-1};
/*#include <signal.h>
void hand(int i)
{
	cout<<"SEGV "<<q.size()<<endl;
	exit(0);
}*/
int main()
{
	//signal(SIGSEGV,hand);
	int m,n;
	
	char c;
	ii start;
	ii end;
	int fnd=0;
	scanf("%d%d%*c",&m,&n);
	assert(m<1001 && n<1001);
	FOR(i,m)
	{
		FOR(j,n)
		{
			scanf("%c",&c);
			if(c=='S')start=make_pair(i,j);
			else if(c=='D')end=make_pair(i,j);
			else if(c=='#')arr[i][j]=-1;
			
		}
		scanf("%*c");
	}
	//cerr<<"DONE WID READ"<<endl;
	q.push(state(start,0));
	int rr,cc,tr,tc;
	int mo;
	while(!q.empty())
	{
		state curr=q.front();
		q.pop();
		rr=curr.pos.first;
		cc=curr.pos.second;
		if(rr==end.first && cc==end.second)
		{
			cout<<curr.moves<<endl;
			fnd=1;
			break;
		}
		visited[rr][cc]=1;
		mo=curr.moves;
		FOR(i,8)
		{
			tr=rr+dirr[i];
			tc=cc+dirc[i];
			if(tr<m && tr>=0 && tc<n && tc>=0)
			{
				if(!visited[tr][tc] && arr[tr][tc]!=-1)
				{
					q.push(state(make_pair(tr,tc),mo+1));
					visited[tr][tc]=1;
				}
			}
		}
		
		
	}
	if(!fnd)cout<<"Impossible"<<endl;
	
	
	
}
