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
 
 
 int inp[2000];
 
 ll max(ll a,int b) {
 	return a<1ll*b?1ll*b:a;
 }
int main(int argc,char** args)
{
	int Te;
	scanf("%d",&Te);
	int L,t,N,C;
	ll ans;
	FOR(kase,Te) {
		scanf("%d%d%d%d",&L,&t,&N,&C);
		FOR(i,C) {
			scanf("%d",&inp[i]);
		}
		int s=0;
		for(int i=C;i<=N;i++) {
			inp[i]=inp[i%C];
		}
		int te;
		int place;
		ll sum=0;
		int poss;
		ll saved=0;
		if(L==0) {
			
			FOR(i,N)sum+=inp[i];
			ans=sum*2;
		}
		else if(L==1) {
			sum=0;
			poss=N+1;
			saved=0;
			FOR(i,N) {
				sum+=inp[i];
				if(2*sum>=t) {
					poss=i+1;
					saved= (2*sum - t )/2;
					break;
				}				
			}
			sum=0;
			FOR(i,N)sum+=inp[i];
			int mx=-1,mxi;
			for(int i=poss;i<N;i++) {
				if(mx<inp[i]) {
					mx=inp[i];
					mxi=i;
				}
			}
			saved=max(saved,mx);
			ans=2*sum - saved;
		}
		else {
			sum=0;
			poss=N+1;
			saved=0;
			FOR(i,N) {
				sum+=inp[i];
				if(2*sum>=t) {
					poss=i+1;
					saved= (2*sum - t )/2;
					break;
				}				
			}
			sum=0;
			FOR(i,N)sum+=inp[i];
			int mx=-1,mxi;
			for(int i=poss;i<N;i++) {
				if(mx<inp[i]) {
					mx=inp[i];
					mxi=i;
				}
			}
			saved+=mx;
			int sx=-1;
			for(int i=poss;i<N;i++) {
				if(i==mxi)continue;
				sx=max(sx,inp[i]);
			}
			saved=max(saved,mx+sx);
			ans= 2*sum - saved;
		}
		cout<<"Case #"<<kase+1<<": "<<ans<<endl;
	}
}
