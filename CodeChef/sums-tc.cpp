
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>


#define FOR(i,a) for(int i=0;i<a;i++)
#define FORS(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a) for(int i=a;i>=0;i--)
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define MAX2(a,b) (a)<(b)?(b):(a)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define LEN(s) strlen(s)
#define tests(tc) int tc;scanf("%d",&tc);while(tc--)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

using namespace std;

uint fast_exp(uint a,uint b,uint mod)
{
	a%=mod;
	ll d=1LL;
	for(uint i=1;i<=b;i<<=1)
	{
		
		if(b&i)
		{
			d*=a;
			d%=mod;
		}
		a*= a;
		a%=mod;
	}
	return (uint)(d%mod);
}

uint solve(uint r,uint n,uint m)
{
	//cerr<<"------[-SOLVE-]------"<<endl;
	//cerr<<"called on r="<<r<<" , n= "<<n<<" , m= "<<m<<endl;
	if(n==1)return 1;
	if(n==0)return 1;
	uint ans=0;
	r%=m;
	
	ans+= (1+r)%m * (solve( ((ll)r * (ll)(r))%m,n/2,m))%m;
	//cerr<<"ANS IS "<<ans<<" b4 n%2"<<endl;
	if(n%2)
	{
		uint temp0=fast_exp(r,n-1,m);
		//cerr<<temp0<<" is being added"<<endl;
		ans+= temp0;
	}
	//cerr<<"ANS IS "<<ans<<endl;
	//cerr<<"------[-SOLVE-ends]------"<<endl;
	return ans%m;
	
}

int main()
{
	tests(tc)
	{
		ll n;
		int m;
		ll ans=0LL;
		scanf("%lld %d",&n,&m);
		if(n==1)
		{
			cout<<(n%m)<<endl;
			continue;
		}
		ll terms= n/m;
		ll left= n-terms*m;
		//cerr<<"ERR "<<terms<<" "<<left<<endl;
		/*uint temp=fast_exp(2,4,100);
		temp=2;
		//cerr<<"TEMP "<<temp<<endl;
		cout<<solve(temp,10,10000000)<<endl;
		cerr<<"EXP "<<(fast_exp(temp,10,100)-1 %100)/((temp-1)%100)<<endl;
		*/
	//	cerr<<"MIN IS "<<MIN2(n+1,m)<<endl;
		
		FORS(i,1,m)
		{
			if(!terms && !left)break;
			//cerr<<"i = "<<i<<endl;
			uint temp1=fast_exp(i,m,m);
		//	cerr<<"r = "<<temp1<<endl;
			ans+= fast_exp(i,i,m)*solve(temp1,terms + (left--?1:0),m)%m;
			ans%=m;
			//cerr<<"ERR "<<ans<<endl;
		}
	
		cout<<ans<<endl;
		
	}
}
