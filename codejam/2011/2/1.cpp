// <-------------------[sWikaseHcAsE]---------------------->
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
#define FORS(i,a,n) for(i=a;i<n;i++)
#define ERR(x) cerr<<#x<<" "<<x<<endl
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
typedef long long double ld;
typedef pair<int,int> P;

#define MAX 1001
int w[MAX];

P dp[MAX];

int main() {
	int i,n,t,s,r,T,kase,x,a,b,len;
	long double ans;
	scanf("%d",&T);
	FOR(kase,T)
	{
		cout<<"Case #"<<kase+1<<": ";
		scanf("%d%d%d%d%d",&x,&s,&r,&t,&n);
		len=0;
		FOR(i,n) {
			scanf("%d%d%d",&a,&b,w+i);
			dp[i].first=w[i];
			dp[i].second=b-a;
			len+=b-a;
		}
		sort(dp,dp+n);
		ans=0;
		
		if(t*r<=x-len)
		{
			FOR(i,n) {
				ans+=(1.0*dp[i].second)/(s+dp[i].first);
			}
			printf("%.8Lf\n",ans+1.0*(x-len-t*r)/s+t);
			continue;
		}
		long double runned=1.0*(x-len)/r;
		long double rem=t-runned;
		FOR(i,n) {
			if(rem>0.0)	{
				if(rem*(r+dp[i].first)>=dp[i].second) {
					ans+=1.0*dp[i].second/(r+dp[i].first);
					rem-=1.0*dp[i].second/(r+dp[i].first);
				}
				else {
					ans+=rem;
					ans+=(1.0*dp[i].second-rem*(r+dp[i].first))/(s+dp[i].first);
					rem=0;
				}
			}
			else {
				ans+=(1.0*dp[i].second)/(s+dp[i].first);
			}
		}

		printf("%.8Lf\n",ans+runned);
	}
}
