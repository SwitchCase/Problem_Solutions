
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

int arr[101][101];
int w,h;
int hi,hj;
int t;
int dp[101][101];
int visited[101][101];
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

inline bool valid(int r,int c)
{
	return (r>=0 && c>=0 && r<w && c<h);
}
int dfs(int r,int c)
{
	cerr<<"CALLED "<<r<<" "<<c<<endl;
	if(!valid(r,c))return 100000000;
	if(r==hi && c==hj)return arr[r][c];
	
	if(visited[r][c])return 10000000;
	
	int ans=1000000;
	visited[r][c]=1;
	FOR(i,4)
	{
		int rr=r+dr[i],cc=c+dc[i];
		int temp=dfs(rr,cc);
		ans=MIN2(ans,temp);
	}
	
	cout<<"returned for "<<r<<" "<<c<<" "<< ans + arr[r][c]<<endl;
	return dp[r][c]= ans + arr[r][c];
	
}

vvii G;

int main()
{
	
	tests(tc)
	{	
		G.clear();
		INIT(arr,0);
		INIT(dp,0);
		INIT(visited,0);
		scanf("%d%d",&w,&h);
		FOR(i,w)
		{
			FOR(j,h)scanf("%d",&arr[i][j]);
		}
		scanf("%d%d%d",&hi,&hj,&t);
		hi--;hj--;
		int ind;
		int rr,cc;
		FOR(i,w)
		{
			FOR(j,h)
			{
				ind=i*h+j;
				vii temp;
				FOR(k,4)
				{
					rr=i+dr[k];
					cc=j+dc[k];
					if(valid(rr,cc))
					{
						temp.pb(ii(rr*h + cc, arr[rr][cc]));
					}
				}
				G.pb(temp);
			}
		}
		VI D(w*h,987654321);
		set<ii> Q;
		D[0]=arr[0][0];
		Q.insert(ii(0,0));
		while(!Q.empty())
		{
			 ii top = *Q.begin();
          	 Q.erase(Q.begin());
           	 int v = top.second, d = top.first;
           	 foreach(it,G[v])
           	 {
           	 	int v2 = it->first, cost = it->second;
                if(D[v2] > D[v] + cost)
                {
                	if(D[v2] != 987654321) 
                	{
                    	Q.erase(Q.find(ii(D[v2],v2)));
                    }
                    D[v2] = D[v] + cost;
                    Q.insert(ii(D[v2], v2));
                }

           	 }

		}
		int ans=D[hi*h+hj];
		if(t-ans>=0)cout<<"YES\n"<<(t-ans)<<endl;
		else cout<<"NO"<<endl;
		
		
		
		
		/*cerr<<"CALLNG DFS\n";
		int ans=dfs(0,0);
		if(t-ans>=0)cout<<"YES\n"<<(t-ans)<<endl;
		else cout<<"NO\n";*/
	}
}
