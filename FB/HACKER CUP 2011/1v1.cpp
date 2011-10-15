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
typedef pair<int,int> ii;
#define F first
#define S second

int raw[150][150];
char M[150][150];
int colors[10][10010][2];
int l[10];
vector<vector<int> > graph;
int visited[150][150];
#define INF -1

string path[10010];

string tostring(int a)
{
	char buff[100];
	sprintf(buff,",%d, ",a);
	return string(buff);
}
int main1(int argc,char** args)
{
	int i,j,k;
	int r,c;
  	char buff[150];
  	int rs,re,cs,ce;
  	int s,e;
  	int N; scanf("%d",&N);while(N--)
	{
			
			FOR(i,10)l[i]=0;
			graph.clear();
			int temp;
			scanf("%d %d",&r,&c);
			FOR(i,r)
			{
				scanf("%s",buff);
				FOR(j,c)
				{
					M[i][j]=buff[j];
					visited[i][j]=0;
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
						temp=raw[i][j];
						if(temp>0)
						{
							colors[temp][l[temp]][0]=i;
							colors[temp][l[temp]++][1]=j;
						}
					}
				}
			}
			int dr[]={0,-1,0,1};
			int dc[]={-1,0,1,0};
			int rr,cc;
		
			queue<pair< pair<int,int>,int> > Q;
			Q.push(make_pair(ii(re,ce),0));
			
			int to;
			//visited[s]=1;
			path[s]="S";
			int n;
			int ans=100000000;
			while(!Q.empty())
			{
				
				pair<ii,int> curr=Q.front();
				
				Q.pop();
				//visited[curr.F]=1;
				int fr=curr.F.F;
				int fc=curr.F.S;
				int w=curr.S;
				cerr<<"Q: "<<fr<<" "<<fc<<" "<<w<<endl;
				if(visited[fr][fc] || M[fr][fc]=='W')continue;
				visited[fr][fc]=w;
				if(M[fr][fc]=='S')
				{
					ans=w;
					break;
				}
				
				FOR(k,4)
				{
					rr=fr+dr[k];
					cc=fc+dc[k];
					if(rr>=0 && rr<r && cc>=0 && cc<c)
					{
						//visited[ rr*c +cc]=w+1;
						Q.push(make_pair(ii(rr, cc),w+1));
					}
				}
				if(raw[fr][fc]>0)
				{
					FOR(k,l[raw[fr][fc]])
					{
						//visited[colors[raw[rr][cc]][k]]=w+1;
						Q.push(make_pair(ii(colors[raw[fr][fc]][k][0],colors[raw[fr][fc]][k][1]),w+1));
					}
				}
				
			}			
			
			cout<<visited[rs][cs]<<endl;
			//cout<<"PATH "<<path[e]<<endl;
			
			
	}			
 	
 	
}


void quicksort1(int *x,int l,int u)
{
	int i,j,t;
	if(l>=u)return;
	t=x[l];
	i=l;
	j=u+1;
	for(;;)
	{
		do i++; while(i<=u && x[i]<t);
		do j--;while(x[j]>t );
		if(i>j)break;
		swap(x[i],x[j]);
	}
	swap(x[l],x[j]);
	quicksort1(x,l,j-1);
	
	quicksort1(x,j+1,u);
}


void quicksort2(int *x,int l,int u)
{	
	int i,j,t;
	if(l>=u)return;
	t=x[l];
	i=l;
	
	for(j=l+1;j<=u;j++)
	{
		if(x[j]<x[l])
			swap(x[++i],x[j]); 
	}
	swap(x[l],x[i]);
	quicksort2(x,l,i-1);
	quicksort2(x,i+1,u);
	
	
}

int comps;

void quicksort_count(int L)
{
	int m;
	if(L<=1)return;
	m=(rand()%L);
	comps+=L-1;
	quicksort_count(m+1);
	quicksort_count(L-m);
}


int dp[1001];
double dpv[1001];
double quicksort_avg(int L)
{
	dpv[0]=0;
	for(int n=1;n<=L;n++)
	{
		double sum=0;
		for(int i=1;i<=n;i++)
			sum+=n-1+dpv[i-1]+dpv[n-i];
		dpv[n]=sum/n;
	}
	return dpv[L];
}
	


int main()
{
	int x[1000];
	int y[1000];
	int i=0;
	while(i<1000)
	{
		int m=(rand()*763)%1000;
		x[i]=m;
		y[i]=m;
		i++;
	}
	quicksort1(x,0,999);
	cout<<"QUICKSORT 1"<<endl;
	quicksort2(y,0,999);
	i=0;
	while(i<1000)
	{
		if(x[i]!=y[i])cout<<"NOT RIGHT"<<endl;
		else cout<<x[i]<<" ";
		i++; 
	}
	cout<<endl;
	FOR(i,1000)dp[i]=0;
	cout<<"AVERAGE "<<quicksort_avg(5)<<endl;
	cout<<"AVERGAE "<<quicksort_avg(10)<<endl;
	cout<<"Average "<<quicksort_avg(100)<<endl;
}
