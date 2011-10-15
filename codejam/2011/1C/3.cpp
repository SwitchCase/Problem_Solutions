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

int inp[1000090];
int tos[1000090];
 
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
		ll sum;
		for(int i=C;i<=N;i++) {
			inp[i]=inp[i%C];
		}
		int poss=N+1;
		ll saved=0;
		sum=0;
		FOR(i,N) {
			sum+=inp[i];
			if(2*sum>=t) {
				poss=i+1;
				saved= (2*sum - t )/2;
				break;
			}				
		}
		int ss=0;
		for(int i=poss;i<N;i++)tos[ss++]=inp[i];
		sort(tos,tos+ss, greater<int>());
		FOR(i,ss-1) {
			if(tos[i] >= tos[i+1] )continue;
			cerr<<"HAHAHAH"<<endl;
		}
		ll p1=0,p2=0;
		for(int i=0;i<L-1 && i<ss;i++) p1 += tos[i];
		for(int i=0;i<L && i<ss;i++) p2+=tos[i];
		saved=max(saved + p1 ,p2);
		sum=0ll;
		FOR(i,N)sum+=inp[i];
		if(L==0)saved=0;
		ans=2*sum - saved;
		cout<<"Case #"<<kase+1<<": "<<ans<<endl;
				
			
	}
 	
 	
}
