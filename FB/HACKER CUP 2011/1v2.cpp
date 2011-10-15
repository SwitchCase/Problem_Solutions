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

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(i,a,n) for(int i=a;i<n;i++)
#define ERR(x) cerr<<#x<<" "<<x<<endl
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> II;

#define F first 
#define S second

char M[150][150];
int visited[150][150];  
int colors[10][10010][2]; 
int l[10];


int dr[4]={0,-1,0,1};
int dc[4]={-1,0,1,0};
	
int main(int argc,char** args)
{
	
	int R,C;
	int rr,cc;
	int er,ec,sr,sc,t;
	char buff[1000];
	int T;scanf("%d",&T);while(T--)
	{
		scanf("%d %d",&R,&C);
		FOR(i,10)l[i]=0;
		FOR(i,R)
		{
			scanf("%s",buff);
			FOR(j,C)
			{
				M[i][j]=buff[j];
				visited[i][j]=-1;
				if(M[i][j]=='S'){ sr=i;sc=j;}
				else if(M[i][j]=='E'){ er=i;ec=j;}
				else if(M[i][j]=='W'){}
				else 
				{
					t=M[i][j]-'0';
					if(t)
					{
						colors[t][l[t]][0]=i;
						colors[t][l[t]++][1]=j;
					}
				}
			}
		}
	//	cerr<<"ENDS AT "<<er<<" "<<ec<<endl;
	//	cerr<<"STARTS AT "<<sr<<" "<<sc<<endl;
		queue<pair<pair<int,int>,int> > Q;
		Q.push(make_pair(make_pair(er,ec),0));
		while(!Q.empty())
		{
			pair<int,int> curr=Q.front().F;
			int x=curr.F;
			int y=curr.S;
			int w=Q.front().S;
			Q.pop();
			cerr<<"Q: "<<x<<" "<<y<<" "<<w<<endl;
			if(visited[x][y]!=-1 || M[x][y]=='W')continue;
			visited[x][y]=w;
			if(M[x][y]=='S')break;
			FOR(i,4)
			{
				int nx=x+dr[i];
				int ny=y+dc[i];
				if(nx>=0 && nx<R && ny>=0 && ny<C)
				{
					Q.push(make_pair(make_pair(nx,ny),w+1));
				}
			}
			t=M[x][y]-'0';
			if(t>0 && M[x][y]!='S' && M[x][y]!='E')
			{
				FOR(i,l[t])
				{
					rr= colors[t][i][0];
					cc=colors[t][i][1];
					Q.push(make_pair(make_pair(rr,cc),w+1));
				}
			}
		}
		cout<<visited[sr][sc]<<endl;
				
	}  
 	
 	
}
