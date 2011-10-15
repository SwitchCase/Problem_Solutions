
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
typedef pair<int,int> ii;

//int dp[15][15][15];
int dp[1<<17][17];
int dist[17][17];
int mat[17][17];
ii sf[17];
ii lst[17];
int arr[17][17];
char re[17][17];
int N;
int vert;
int n[17],c[17];
/*
int dfs(int rr,int cc,int frm,int to)
{
	
	if(rr>=N || rr<0 || cc>=N || cc<0)
	{
		cerr<<"CALLING "<<rr<<" "<<cc<<" "<<frm<<" "<<to<<"returning 9873132"<<endl;
		return 987654321;
	}
	if(arr[rr][cc]==-1)
	{
		cerr<<"CALLING "<<rr<<" "<<cc<<" "<<frm<<" "<<to<<"returning 987adsd3132"<<endl;
		return dp[rr][cc][to]=987654321;
	}
	if(dp[rr][cc][to]!=-1)
	{
		cerr<<"CALLING "<<rr<<" "<<cc<<" "<<frm<<" "<<to<<"returning--- "<<dp[rr][cc][to]<<endl;
		return dp[rr][cc][to];
	}
	dp[rr][cc][to]=987654321;
	if(arr[rr][cc]==to)
	{
		cerr<<"CALLING "<<rr<<" "<<cc<<" "<<frm<<" "<<to<<"returning 0"<<endl;
		return dp[rr][cc][to]=0;
	}
	if(frm==to)return 0;
	
	int ans=dfs(rr+1,cc,frm,to);
	ans=min(ans,dfs(rr-1,cc,frm,to));
	ans=min(ans,dfs(rr,cc-1,frm,to));
	ans=min(ans,dfs(rr,cc+1,frm,to));	
	cerr<<"CALLING "<<rr<<" "<<cc<<" "<<frm<<" "<<to<<"returning "<<(1+ans)<<endl;
	return dp[rr][cc][to]=1+ans;
}

*/
int visited[18][18];
int bfs(int,int,int);
int dfs2(int rr,int cc,int to)
{
	return bfs(rr,cc,to);
	if(rr>=N || rr<0 || cc>=N || cc<0)
	{
		//cerr<<"CALLING "<<rr<<" "<<cc<<" "<<to<<"returning 9873132"<<endl;
		return 987654321;
	}
	if(arr[rr][cc]==-1)
	{
		//cerr<<"CALLING "<<rr<<" "<<cc<<" "<<to<<"returning 987adsd3132"<<endl;
		return 987654321;
	}
	
	if(visited[rr][cc]!=-1)return visited[rr][cc];
	
	visited[rr][cc]=987654321;
	if(arr[rr][cc]==to)
	{
		//cerr<<"CALLING "<<rr<<" "<<cc<<" "<<to<<"returning 0"<<endl;
		return visited[rr][cc]=0;
	}
	
	
	int ans=dfs2(rr,cc+1,to);
	ans=min(ans,dfs2(rr-1,cc,to));
	ans=min(ans,dfs2(rr,cc-1,to));
	ans=min(ans,dfs2(rr+1,cc,to));	
//	cerr<<"CALLING "<<rr<<" "<<cc<<" "<<to<<"returning "<<(1+ans)<<endl;
	return visited[rr][cc]=1+ans;
}

struct item
{
	int r;
	int c;
	int d;
};
int bfs(int rr,int cc,int to)
{
	int dr[]={0,1,0,-1};
	int dc[]={-1,0,1,0};
	queue<item> Q;
	item s;
	s.r=rr;
	s.c=cc;
	s.d=0;
	int bv[16][16];
	INIT(bv,-1);
	Q.push(s);
	int tr,tc;
	bv[rr][cc]=1;
	while(!Q.empty())
	{
		item curr=Q.front();
		Q.pop();
		if(arr[curr.r][curr.c]==to)return curr.d;
		FOR(i,4)
		{
			tr=curr.r+dr[i];
			tc=curr.c+dc[i];
			if(tr<0 || tc<0 || tr>=N || tc>=N)continue;
			if(bv[tr][tc]!=-1)continue;
			if(arr[tr][tc]==-1)continue;
			bv[tr][tc]=1;
			item temp;
			temp.r=tr;
			temp.c=tc;
			temp.d=curr.d+1;
			Q.push(temp);
		}
	}
	return 987654321;
}



int fun(int S,int s)
{
	if(S==(1<<s))return mat[s][0];
	int &v=dp[S][s];
	if(v>0)return v;
	v=987654321;
	FOR(i,vert+1)
	{
		if(i!=s)
		{
			if(S&(1<<i))
			{
				v=min(v,mat[s][i]+fun(S-(1<<s),i));
			}
		}
	}
	//cout<<"FUN "<<S<<"  "<<s<<"  "<<v<<endl;
	return v;
}


int main()
{
	tests(tc)
	{
		scanf("%d",&N);
		scanf("%*c");
	//	cerr<<"N = "<<N<<endl;
		INIT(dp,-1);
		INIT(arr,0);
		int tot=1;
		FOR(i,N)
		{
			FOR(j,N)
			{	
				scanf("%c",&re[i][j]);
				//cerr<<" READ AS "<<re[i][j]<<endl;
				if(re[i][j]=='#')arr[i][j]=-1;
				else if(re[i][j]=='*')
				{
					sf[tot].first=i;
					sf[tot].second=j;
					arr[i][j]=tot++;
				}
				else arr[i][j]=0;
			}
			scanf("%*c");
		}
		arr[0][0]=-2;
		arr[N-1][N-1]=tot;
		vert=tot;
	//	cerr<<"TOTAL *s = "<<tot<<endl;
		int ans;
		FOR(i,tot-1)
		{
			//cerr<<"======TYPE 1======"<<"  "<<(i+1)<<"  "<<"============="<<endl;
			INIT(visited,-1);
			ans=dfs2(0,0,i+1);
			//ans=dfs(0,0,-2,i+1);
			//if(ans>=987654321)ans=-1;
			lst[i+1].first=ans;
		}
	//	cerr<<"STARTING DONE"<<endl;
		FORS(i,1,tot)
		{
			FORS(j,i+1,tot)
			{
				//cerr<<"======TYPE 2======"<<"  "<<i<<" , "<<j<<"  "<<"============="<<endl;
				/*dp[sf[i].first][sf[i].second][j]=-1;
				ans=dfs(sf[i].first,sf[i].second,i,j);*/
				INIT(visited,-1);
				ans=dfs2(sf[i].first,sf[i].second,j);
			//	if(ans>=987654321)ans=-1;
				dist[i][j]=ans;
				dist[j][i]=ans;
			//	dp[sf[j].first][sf[j].second][i]=ans;
			}
		}
	//	cerr<<"MIDDLE DONE"<<endl;
		FOR(i,tot)
		{
			//cerr<<"======TYPE 3======"<<"  "<<(i+1)<<"  "<<"============="<<endl;
			/*dp[sf[i+1].first][sf[i+1].second][tot]=-1;
			ans=dfs(sf[i+1].first,sf[i+1].second,i+1,tot);*/
			INIT(visited,-1);
			ans=dfs2(sf[i+1].first,sf[i+1].second,tot);
		//	if(ans>=987654321)ans=-1;
			lst[i+1].second=ans;
		}
		/*
		cerr<<"PRINTING LST "<<endl;
		FOR(i,tot-1)
		{
			cerr<<lst[i+1].first<<"  "<<lst[i+1].second<<endl;
		}
		cerr<<"_______________"<<endl;
		cerr<<"PRINTING MATRIX  "<<endl;
		FOR(i,tot-1)
		{
			FOR(j,tot-1)
			{
				cerr<<dist[i+1][j+1]<<"  ";
			}
			cerr<<endl;
		}*/
		INIT(mat,0);
		FOR(i,tot-1)
		{
			mat[0][i+1]=lst[i+1].first;
		
			mat[i+1][0]=mat[0][i+1];
			mat[tot][i+1]=mat[i+1][tot]=lst[i+1].second;
		}
		mat[tot][0]=0;
		INIT(visited,-1);
		ans=dfs2(0,0,tot);
		//if(ans>=987654321)ans=-1;
		mat[0][tot]=ans;
		FORS(i,1,tot)
		{
			FORS(j,1,tot)
			{
				mat[i][j]=dist[i][j];
			}
		}
		
	//	FOR(i,tot+1)FOR(j,tot+1)mat[i][j]*=-1;
	/*	FOR(i,tot+1)n[i]=c[i]=mat[0][i];
		cerr<<"*****************************"<<endl;
		FOR(i,tot+1)
		{
			FOR(j,tot+1)
			{
				cerr<<mat[i][j]<<" ";
			}
			cerr<<endl;
		}
		*/
		
		ans=fun((1<<(tot+1))-1,0);
		if(ans>987654321)ans=-1;
		cout<<ans<<endl;
	
		
	//	cerr<<"________________"<<endl;
		
	//	cerr<<"---------------[END OF CASE]----------------"<<endl;
	}
	
}
