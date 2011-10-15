// <-------------------[sWitCHcAsE]---------------------->
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<vector>
#include<map>
#include<cstring>
#include<cassert>
#include<queue>

#define FOR(i,n) for(i=0;i<n;i++)
#define FORS(i,a,n) for(i=a;i<n;i++)
#define ERR(x) cerr<<#x<<" "<<x<<endl
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
typedef long double ld;
#define F first
#define S second

int raw[150][150];
vector<int> colors[10];
vector<vector<int> > graph;
int visited[10010];
#define INF 1000000000

string path[10010];

string tostring(int a)
{
	char buff[100];
	sprintf(buff,",%d, ",a);
	return string(buff);
}
int main(int argc,char** args)
{
	int i,j,k;
	int r,c;
  	char buff[150];
  	int rs,re,cs,ce;
  	int s,e;
  	int N; scanf("%d",&N);while(N--)
	{
			memset(raw,-1,sizeof raw);
			FOR(i,10)colors[i].clear();
			graph.clear();
			scanf("%d %d",&r,&c);
			FOR(i,r)
			{
				scanf("%s",buff);
				FOR(j,c)
				{
					visited[i*c +j]=0;
					if(buff[j]=='W')
					{
						raw[i][j]=INF;
					}
					else if(buff[j]=='S')
					{
						raw[i][j]=0;
						rs=i;
						cs=j;
						s=i*c+j;
					}
					else if(buff[j]=='E')
					{
						raw[i][j]=0;
						re=i;
						ce=j;
						e=i*c+j;
					}
					else
					{
						raw[i][j]=buff[j]-'0';
						if(raw[i][j]>0)colors[raw[i][j]].pb(i*c + j);
					}
				}
			}
			int dr[]={1,-1,0,0};
			int dc[]={0,0,-1,1};
			int rr,cc;
			cerr<<"COLORS "<<endl;
			cerr<<"S AT "<<s<<" E AT "<<e<<endl;
			FOR(i,10)
			{
				cerr<<i<<" ::: ";
				FOR(j,colors[i].size())cerr<<colors[i][j]<<" ";
				cerr<<endl;
			}
			cerr<<"COLORS "<<endl;
			FOR(i,r)
			{
				FOR(j,c)
				graph.pb(vector<int>());
			}
			graph.pb(vector<int>());
			FOR(i,r)
			{
				FOR(j,c)
				{
					
					if(raw[i][j]>=INF)continue;
					FOR(k,4)
					{
						rr=i+dr[k];
						cc=j+dc[k];
						if(rr>=0 && cc>=0 && rr<r && cc<c)
						{
							if(raw[rr][cc]>=INF)continue;
							graph[i*c+j].pb(rr*c + cc);
						
						}
					}
					if(raw[i][j]>0 && raw[i][j]<10)
					{
						FOR(k,colors[raw[i][j]].size())
						{
							if(colors[raw[i][j]][k]!= i*c+j)
								graph[i*c +j].pb(colors[raw[i][j]][k]);
						}
					}
				}
			}
			cerr<<"GRAPH of size "<<graph.size()<<endl;
			FOR(i,graph.size())
			{
				cerr<<i<<" :::: ";
				FOR(j,graph[i].size())cerr<<graph[i][j]<<" ";
				cerr<<endl;
			}
			cerr<<"GRAPH END "<<endl;
			
			queue<pair<int,int> > Q;
			Q.push(make_pair(s,0));
			int ans=0;
			int to;
			visited[s]=1;
			path[s]="S";
			while(!Q.empty())
			{
				pair<int,int> curr=Q.front();
				Q.pop();
				visited[curr.F]=1;
				FOR(i,graph[curr.F].size())
				{
					to=graph[curr.F][i];
					path[to]=path[curr.F]+ tostring(curr.F);
					if(to==e)
					{
						ans=curr.S +1;
						break;
					}
					else
					{
						if(!visited[to])
						{
							Q.push(make_pair(to,curr.S +1 ));
							if
							visited[to]=min(visited[to];
						}
						else
						{
							if(to==217)cerr<<"MMMMMMMMMMMOOOOOOOOORRRRRROOOOOOONNNNNN"<<endl;
						}
					}
				}
			}			
			
			cout<<ans<<endl;
			cout<<"PATH "<<path[e]<<endl;
			
			
	}			
 	
 	
}
