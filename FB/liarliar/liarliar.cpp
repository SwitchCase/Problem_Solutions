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
#define ERR(x) cerr<<#x<<" "<<x<<endl
#define pb push_back
using namespace std;
#define MAX 1000005
typedef vector<int> VI;
int n;
vector<VI> vvi;
int color[MAX];

void solve(int a,int b)
{
	queue<int> q;
	q.push(a);
	color[a]=b;
	int curr,i;
	while(!q.empty())
	{
		curr=q.front();q.pop();
		b=color[curr];
		for(i=0;i<vvi[curr].size();i++)
		{
			if(color[vvi[curr][i]]==-1)
			{
				q.push(vvi[curr][i]);
				color[vvi[curr][i]]=!b;
			}
		}
	}
	
}
 
 
int main(int argc,char** args)
{
    freopen(args[1],"r",stdin);
    map<string,int> mp;
 	scanf("%d",&n);
 	string t,t1;
 	int ind1,ind2;
 	int f=0;
 	int m;
 	FOR(i,n)vvi.pb(VI());
 	FOR(i,n)
 	{
 		cin>>t;
 		if(mp.find(t)!=mp.end()) ind1=mp[t];
 		else 
 		{
 			mp[t]=ind1=f;
 			f++;
 		}
 		cin>>m;
 		FOR(j,m)
 		{
 			cin>>t1;
 			if(mp.find(t1)!=mp.end())ind2=mp[t1];
 			else
 			{
 				mp[t1]=ind2=f;
 				f++;
 			}
 			vvi[ind1].pb(ind2);
 			vvi[ind2].pb(ind1); 			
 		}
 	}
 	
 	//FOR(i,vvi.size()){cout<<i<<" : CHILD : :: ";FOR(j,vvi[i].size())cout<<vvi[i][j]<<" ";cout<<endl;}
 	memset(color,-1,sizeof color);
 	solve(0,0);
 	int ans=0;
 	FOR(i,n)if(color[i]==1)ans++;
 	//cerr<<"RET "<<ans<<endl;
 	ans=max(ans,n-ans);
 	n=min(ans,n-ans);
 	cout<<ans<<" "<<n<<endl;
 	
 	
}
