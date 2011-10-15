
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
char inp[1024];
int dfsn[102];
int low[102];
int timed;
int ans[101];
int component;
int partof[102];
int noofcomp[102];
int children[102];
int level[102];
vector<vector<int> > graph;

void dodfs(int ind)
{
	partof[ind]=component;
	noofcomp[component-1]++;
	
	
	timed++;
	dfsn[ind]=timed;
	int min=dfsn[ind];
	low[ind]=dfsn[ind];
	int &child=children[ind];
	int v;
	FOR(i,graph[ind].size())
	{	
		v=graph[ind][i];
		if(dfsn[v]==-1)
		{
			level[v]=level[ind]+1;
			child++;
			dodfs(v);
			low[ind]= (low[ind]<low[v]?low[ind]:low[v]);
			if(dfsn[ind]==1)//root 
			{
				if(child>=2)//children >=2, articulation point
				{
					ans[ind]=1;
				//	cerr<<"ART :"<<(ind+1)<<endl;
				}
			}
			else if(low[v]>=dfsn[ind])
			{
				//articulation point
				ans[ind]=1;
			//	cerr<<"ART(2) :"<<(ind+1)<<endl;
			}
			
		}
		else
		{
			if(level[v]<level[ind]-1)
			{
				low[ind]=(low[ind]<dfsn[v]?low[ind]:dfsn[v]);
			}
		}
	}
	
}

void printgraph()
{
	cerr<<"*******************"<<endl;
	FOR(i,n)
	{
		cerr<<(i+1)<<" => ";
		FOR(j,graph[i].size())
		{
			cerr<<(graph[i][j]+1)<<" ";
		}
		cerr<<endl;
	}
	cerr<<"*******************"<<endl;
}
int main()
{
	int ind=-1,tem;
	int s;
	while(1)
	{
		cin.getline(inp,sizeof inp);
		sscanf(inp,"%d",&n);
		timed=0;
		INIT(ans,0);
		graph.clear();
		FOR(i,n)
		{
			VI temp;
			graph.pb(temp);
		}
		if(n==0)break;
		VS in;
		fflush(stdin);
		FOR(i,n+1)
		{
		
			cin.getline(inp,sizeof inp);
			
			in=split(string(inp)," ");
			//cerr<<"1"<<endl;
			if(in[0]=="0")break;
			
			sscanf(in[0].c_str(),"%d",&ind);
			
			FORS(i,1,in.size())
			{
				sscanf(in[i].c_str(),"%d",&tem);
				graph[tem-1].pb(ind-1);
				graph[ind-1].pb(tem-1);
			}
			
		}
		//printgraph();
		INIT(dfsn,-1);
		int calls=0;
		component=1;
		INIT(noofcomp,0);
		INIT(children,0);
		INIT(level,0);
		FOR(i,n)
		{
			if(dfsn[i]==-1)
			{
				//cerr<<"DFS ON "<<i<<endl;
				level[i]=0;
				dodfs(i);
				component++;
				calls++;
			}
		}
		int a=0;
		FOR(i,n)
		{
			if(ans[i])a++;
		}
		//cerr<<"ANS ";
		if(calls==1)
		cout<<a<<endl;
		else
		{
			//cerr<<"ANS : "<<endl;
			int ret=0;
			FOR(i,component-1)
			{
				if(component>3)ret+=noofcomp[i];
				else
				{
					if(noofcomp[i]>1)ret+=noofcomp[i];
				}
			}
			cout<<ret<<endl;
		}
	}
}
