
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

int s,e;
char awake[10];
int ind['Z'];
int mat[50][50];
vector<VI> G;
int tota[35];
int conn[30];
char buff[10];
int main()
{
	char cx,cy;
	int x,y;
	while(1)
	{
		G.clear();
		if(scanf("%d%d%*c",&s,&e)==EOF)break;
		cin.getline(awake,10);
	//	cout<<" INP :"<<endl;
	//	cout<<s<<" "<<e<<endl;
	//	cout<<awake<<endl;		
		fflush(stdin);
		
		int n=0;
		INIT(ind,-1);
		INIT(mat,0);
		INIT(conn,0);
		INIT(tota,-1);
		int idt=0;
		int dist=0;
		for(int i=0;awake[i];i++)
		{
			if(ind[awake[i]]==-1)
			{
				dist++;
				ind[awake[i]]=n++;
				tota[idt++]=(n-1);
			}
		}
		//FOR(i,3)cerr<<"IND OF "<<awake[i]<<" "<<ind[awake[i]]<<endl;
	
		FOR(i,e)
		{
			cin.getline(buff,10);
			if(strlen(buff)<1)
			{
			//	cerr<<"ASDASD"<<endl;
				
			}
			cx=buff[0];
			cy=buff[1];
			//cout<<cx<<cy<<endl;
			assert(cx>='A' && cx<='Z');
			assert(cy>='A' && cy<='Z');
			if(cx==cy)continue;
			if(ind[cx]!=-1)
				x=ind[cx];
			else
			{
				 x=ind[cx]=n++;	
				// cerr<<"IND OF "<<cx<<" "<<x<<endl;
			}
			if(ind[cy]!=-1)
				y=ind[cy];
			else
			{
				 y=ind[cy]=n++;
				 //cerr<<"IND OF "<<cy<<" "<<y<<endl;
			}
			mat[x][y]=1;
			mat[y][x]=1;
		}
		FOR(i,n)
		{
			VI temp;
			G.pb(temp);
		}
		FOR(i,n)
		{
			FOR(j,n)
			{
				if(mat[i][j]==1)
				{
					G[i].pb(j);
				}
			}
		}/*
		cerr<<"----------------------"<<endl;
		FOR(i,n)
		{
			FOR(j,n)cerr<<mat[i][j]<<" ";
			cerr<<endl;
		}
		cerr<<"----------------------"<<endl;
		cerr<<"----------------------"<<endl;
		FOR(i,G.size())
		{
			cerr<<i<<" : ";
			FOR(j,G[i].size())cerr<<G[i][j]<<" ";
			cerr<<endl;
		}
		cerr<<"----------------------"<<endl;*/
		if(dist<3 && s>=3)
		{
			printf("THIS BRAIN NEVER WAKES UP\n");
			continue;
		}
		else if(dist==s)
		{
			printf("WAKE UP IN, 0, YEARS\n");
			continue;
		}
		int tem;
		int left=s-dist;
		int time=0;
		int added=0;
		for(time=0;time<(s+1) && left>0;time++)
		{
			tem=0;
			INIT(conn,0);
			added=0;
			while(tota[tem]!=-1)
			{
				FOR(j,G[tota[tem]].size())
				{
					conn[G[tota[tem]][j]]++;
				}
				tem++;
			}
			tem=0;
			while(tota[tem]!=-1)
			{
				conn[tota[tem++]]=0;
			}
			//cerr<<"FOR TIME "<<time<<endl;
			FOR(j,n)
			{
				//cerr<<"CONN of "<<j<<"  = "<<conn[j]<<endl;
				if(conn[j]>=3)
				{
					tota[idt++]=j;
					left--;
					added++;
				}
			}
			if(!added)break;
			//cerr<<"--------------------"<<endl;
		}
		//cerr<<"LEFT :"<<left<<endl;
		if(left)printf("THIS BRAIN NEVER WAKES UP\n");
		else printf("WAKE UP IN, %d, YEARS\n",time);
				
	}
}
