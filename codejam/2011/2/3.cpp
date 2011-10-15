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
#define FORS(i,a,n) for(i=a;i<n;i++)
#define ERR(x) cerr<<#x<<" "<<x<<endl
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
typedef long double ld;
 
vector<int> primes;
int pr[1000001]={0};

#define M 1000000
int doStart() {
	primes.pb(2);
	for(int i=4;i<=M;i+=2)pr[i]=1;
	
	for(int i=3;i*i<=M;i+=2) {
		if(!pr[i]) {
			primes.pb(i);
			for(int j=i*i;j<=M;j+=2*i)pr[j]=1;
		}
	}
	for(int i=1001;i<=M;i++)if(!pr[i])primes.pb(i);
	
}

 

int gcd(int a,int b) {
	if(b==0)return a;
	else return gcd(b,a%b);
}
int main(int argc,char** args)
{
	doStart();
	cerr<<"SIZE OF PR "<<primes.size()<<endl;
 	int T;
 	ll N;
 	int n=primes.size();
 	//cerr<<"SIZE IS "<<n<<endl;
 	scanf("%d",&T);
 	FOR(kase,T) {
 		cout<<"Case #"<<kase+1<<": ";
 		scanf("%lld",&N);
 		if(N==1) {
 			cout<<"0\n";
 			continue;
 		}
 		int large=1;
 		int small=0;
 		ll curr=1;
 		int g;
 		int ans=1;
 		FOR(i,n) {
 			if(N>=primes[i]) {
 				int lg=0;
 				ll p=primes[i];
 				ll x=p;
 				while(x<=N) {
 					x*=p;
 					lg++;
 				}
 				ans+=(lg-1);
 			}
 			else break;
 		}
 		
 		cout<<ans<<endl;
 	}
 	
}
