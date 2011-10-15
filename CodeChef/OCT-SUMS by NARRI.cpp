#include <vector>
#include <iostream>
using namespace std;
char isp[200500];

inline long long fixmod(long long a,long long mod)
{
	return ((a%mod)+mod)%mod;
}

long long powmod(long long n,long long p,long long MOD)
{
	n %= MOD;
/*	if(MOD != 2)
	{
		p %= MOD-1;
	}*/
	long long out = 1,z = n;
	for(long long i=1;i<=p;i<<=1)
	{
		if((p&i) != 0)
		{
			out *= z;
			out %= MOD;
		}
		z *= z;
		z %= MOD;
	}
	return out;
}

pair<long long,long long> brent(const long long mult,const long long MOD)
{
#define f(x) (((x)*mult)%MOD)
	long long power,lam;
	power = lam = 1;
	long long turtle,hare;
	turtle = 1;
	hare = f(1);
	while(turtle != hare)
	{
		if(power==lam)
		{
			turtle = hare;
			power *= 2;
			lam = 0;
		}
		hare = f(hare);
		lam += 1;
	}
	long long mu = 0;
	turtle = hare = 1;
	for(long long i=0;i<lam;++i)
	{
		hare = f(hare);
	}
	while(turtle != hare)
	{
		turtle = f(turtle);
		hare = f(hare);
		mu += 1;
	}
	return make_pair(lam,mu);
#undef f
}

inline long long phi(long long x)
{
	long long end = min(x,200500LL);
	long long out = x;
	for(long long i=0;i<=end;++i)
	{
		if(isp[i] && (x%i)==0)
		{
			out -= out/i;
		}
	}
	return out;
}

inline long long invmod(long long n,long long MOD)
{
	return powmod(n,MOD-2,MOD);
}

long long gcd(long long a,long long b)
{
	if(a>b){swap(a,b);}
	long long c;
	while(b)
	{
		c = b;
		b = a%b;
		a = c;
	}
	return a;
}

int used[200500];
long long partial[200500];

long long geo_series_sum(long long rate,long long n,long long MOD)
{
	rate = fixmod(rate,MOD);
	if(n==0){return 0;}
	if(rate==1){return n%MOD;}
	if(gcd(rate,MOD)==1)
	{
		return fixmod(fixmod(1 - powmod(rate,n,MOD),MOD)*powmod((1-rate+MOD)%MOD,phi(MOD)-1,MOD),MOD);
	}
	

}

long long PHIMOD;

long long gss(long long rate,long long n,long long MOD)
{
	if(rate==1){return n%MOD;}
	if(n<5)
	{
		long long out = 0LL;
		long long curr = 1LL;
		for(long long i=0;i<n;++i)
		{
			out += curr;
			curr *= rate;
		}
		return out%MOD;
	}
	if(gcd(rate,MOD)==1)
	{
		return fixmod(fixmod(1 - powmod(rate,n,MOD),MOD)*powmod((1-rate+MOD)%MOD,PHIMOD-1,MOD),MOD);

	}
	else
	{
		//decompose problem
		long long out = ((1+rate)%MOD)*gss((rate*rate)%MOD,n/2,MOD);
		out %= MOD;
		if((n&1)==1)
		{
			//odd
			out += powmod(rate,n-1,MOD);
			out %= MOD;
		}
		return out;
	}
	
}

long long gg(long long r,long long n,long long M)
{
	r = fixmod(r,M);
	return gss(r,n,M);
}

pair<long long,long long> egcd(long long a,long long b)
{
	bool ss = false;
	if(b==0)
	{
		return make_pair(1LL,0LL);
	}
	else if(a%b==0)
	{
		return make_pair(0LL,1LL);
	}
	else
	{
		pair<long long,long long> ret = egcd(b,a%b);
		ret = make_pair(ret.second,ret.first-ret.second*(a/b));
		return ret;
	}
}
//assumes MOD is prime
long long primesolve(long long n,long long MOD,long long P)
{
	long long out = 0;
	long long base = (n/MOD);
	long long mo = (n%MOD);
	PHIMOD = phi(MOD);
	for(long long i=1;i<=mo;++i)
	{
		out += powmod(i,i,MOD)*gg(powmod(i,MOD,MOD),base+1,MOD);
		out %= MOD;
	}
	for(long long i=mo+1;i<MOD;++i)
	{
		out += powmod(i,i,MOD)*gg(powmod(i,MOD,MOD),base,MOD);
		out %= MOD;
	}
	return out;

}

long long chinese_rem(vector<long long> mods,vector<long long> results,long long N)
{
	long long ret = 0;
	for(int i=0;i<mods.size();++i)
	{
		pair<long long,long long> p = egcd(mods[i],N/mods[i]);
		ret += (results[i]*p.second*(N/mods[i]));
		ret %= N;
		ret += N;
		ret %= N;
	}
	return ret;
}


int main(int argc,char **argv)
{
	if(argc>1){freopen(argv[1],"r",stdin);}
	int CASES;
	cin >> CASES;
	memset(isp,1,sizeof(isp));
	isp[0] = isp[1] = 0;
	for(int i=2;i<200500;++i)
	{
		if(!isp[i])continue;
		for(int j=i+i;j<200500;j+=i)
		{
			isp[j] = 0;
		}
	}


	for(int i=0;i<CASES;++i)
	{
		//if(i%1000 == 0){cerr << i << '\r';}
		long long n,nn,m;
		//cin >> n >> m;
		scanf("%lld %lld",&n,&m);
	//	fprintf(stderr,"%lld %lld\n",n,m);
		nn = n;
		long long mm = m;
#define win(x) printf("%lld\n",(x));fflush(stdout);
		if(n==1)
		{
			win(fixmod(1,m));
		}
		else if(m==1)
		{
			win(0LL);
		}
		//divide out primes
		else if(isp[m])
		{
			win(fixmod(primesolve(n,m,m),m));
		}
		else
		{
			vector<long long> mods,res;
			mods.clear();
			res.clear();
			for(int i=2;i<200500;++i)
			{
				if(isp[i] && (m%i)==0)
				{
					long long t = 1;
					while((m%i)==0){t *= i;m/=i;}
					mods.push_back(t);
					res.push_back(primesolve(nn,t,i));
				}
			}
		
			if(res.size()==1)
			{
				win(fixmod(res[0],mm));
			}
			else
			{
			win(fixmod(chinese_rem(mods,res,mm),mm));
			}
		}

	}
	return 0;
}

