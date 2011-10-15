
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

int n;
#define maxm 100001
string fact[maxm];
int sieve[maxm]={0};
int primes[maxm];
int p=0;

string itoa(int n)
{
	string ans="";
	while(n)
	{
		ans += '0'+(n%10);
		n/=10;
	}
	reverse(ans.begin(),ans.end());
//	cerr<<"RET "<<ans<<endl;
	return ans;
}
void Esieve()
{
	for(int i=2;i<maxm;i++)
	{
		if(!sieve[i])
		{	
			fact[i]= itoa(i);
			primes[p++]=i;
			for(int j=2*i;j<maxm;j+=i)
			{
				sieve[j]=1;
				int k=j;
				while(k%i==0)
				{
					fact[j]+=" x ";
					fact[j]+=itoa(i);
					k/=i;
				}
			}
		}
	
	}
}


void PrintFactors(int n)
{
	VI factors;
	bool X=false;
	if(abs(n)>=maxm)
		{
			if(n<0)
			{	
				n*=-1;			
				cout<<"-1 x ";
			}
			while(n%2==0)
			{
				cout<<"2";
				n/=2;
				if(n!=1){cout<<" x ";X=true;}
			}
			if(n<maxm)
			{
				if(sieve[n])
				cout<<(fact[n].substr(3,fact[n].size()-1))<<endl;
				else cout<<fact[n]<<endl;
				return;
			}
			bool done=false;
			//cerr<<"BLAH"<<endl;9999999
			int tn=n;
			for(int i=3;1LL*i*i<=1LL*tn;i+=2)
			{
				//cerr<<i<<"I*I = "<<i*i<<endl;
				if(n%i==0 && !sieve[i])
				{
					//cerr<<i<<" is a fact"<<endl;
					done=true;
					while(n%i==0)
					{
						factors.pb(i);
						//cerr<<"pushed "<<i<<endl;
						n/=i;
						
					}
					int k=n/i;
					while(k!=0 && k!=1&& n%k==0 && !sieve[k])
					{
						
						factors.pb(k);
						//cerr<<"pushed k= "<<k<<endl;
						n/=k;
					}
				}
			
			}
			if(!done)
			{
				//cerr<<"PRINTING HERE\n";
				cout<<n<<endl;
				return;
			}
			sort(factors.begin(),factors.end());
			for(int m=0;m<factors.size();m++)
			{
				cout<<factors[m];
				if(m!=factors.size()-1){
				cout<<" x ";X=true;}
			}
			X=false;
			if(n<maxm && n!=1)
			{
				if(!sieve[n]){cout<<" x "<<n;X=false;}
				else cout<<fact[n];
			}
			else if(n!=1)
			{
				if(!X)cout<<" x ";
				PrintFactors(n);
			}
			cout<<endl;
			//cerr<<"END OF BLAH "<<endl;
		}
		else
		{
			if(n<0)
			{
				cout<<"-1";
				if(!sieve[abs(n)])cout<<" x ";
				cout<<fact[abs(n)]<<endl;
			}
			else
			{
				if(sieve[n])
				cout<<(fact[n].substr(3,fact[n].size()-1))<<endl;
				else cout<<fact[n]<<endl;
			}	
		}
}
int main()
{
	Esieve();
	//cerr<<"SIEVE IS DONE"<<endl;
	VI factors;
	while(1)
	{
		factors.clear();
		scanf("%d",&n);
		if(!n)break;
		cout<<n<<" = ";
		PrintFactors(n);
	}
}
