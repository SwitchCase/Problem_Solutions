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
 
ll gcd(ll a,ll b) {
	if(b==0) return a;
	else return gcd(b,a%b);
}
 ll inp[10100];
 
 ll A[70],B[70];
 
 int check(ll a,ll b) {
 	ld lga=log(a);
 	ld lgb=log(b);
 	if(lga + lgb > 17.0)return 0;
 	return 1;
 }
int main(int argc,char** args)
{
	int T;
	scanf("%d",&T);
	int n;
	ll l,h;
	ll ans;
	FOR(kase,T) {
		scanf("%d%lld%lld",&n,&l,&h);
		FOR(i,n)scanf("%lld",&inp[i]);
		sort(inp,inp+n);
		cout<<"Case #"<<kase+1<<": ";
		ll sm=inp[0];
		ll g;
		ans=-1;

		for(int i=1;i<n;i++) {
			if(sm%inp[i]==0 || inp[i]%sm==0) {
				if(sm!=1)sm=min(sm,inp[i]);
				else sm=inp[i];
				continue;
			}
			g=gcd(sm,inp[i]);
			sm= (sm/g)*inp[i];
			if(sm>h) {
				ans=-1;
				break;
			}
		}
		g=inp[0];
		for(int i=1;i<n;i++) g=gcd(g,inp[i]);
		ll temp=1;		
		if(sm<=h && sm>=l) {
			ans=sm;
		}		
		else if(sm<=l){
			temp=1;
			if(g==1) {
				while(temp<=h) {
					temp*=sm;
					if(temp>=l && temp <=h){	
						ans=temp;
						break;
					}
				}
			}
			else {
				ll tans=-1;
				temp=1;
				int a=0,b=0;
				while(temp<=h) {
					A[a++]=temp;
					temp*=g;
				}
				temp=1;
				while(temp<=h) {
					B[b++]=temp;
					temp*=sm;
				}
				temp=1;
				FOR(i,a) {
					FOR(j,b) {
						ll cc=A[i]*B[j];
						if(check(A[i],B[j]) && cc <=h && cc>=l) {
							if(tans==-1)tans=cc;
							else tans=min(tans,cc);
						}
					}
				}
				ans=tans;
			}	
		}
		if(ans==-1) {
			cout<<"NO"<<endl;
		}
		else cout<<ans<<endl;
		
	}
 	
 	
}
