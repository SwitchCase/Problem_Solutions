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

#define FOR(i,n) for(i=0;i<n;i++)
#define FORS(i,a,n) for(i=a;i<n;i++)
#define ERR(x) cerr<<#x<<" "<<x<<endl
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef unsigned long long ull;
typedef long double ld;
 

ull gcd(ull a,ull b)
{
	if(b==0)return a;
	else return gcd(b,a%b);
}
 
vector<ull> top,bot;
int main(int argc,char** args)
{
   unsigned long long ans,n,k;
  int t;scanf("%d",&t);
  while(t--)
  {
  	top.clear();bot.clear();
  	scanf("%llu %llu",&n,&k);
  	if(k>n){cout<<"0"<<endl;continue;}
  	if(k==1 || k==n-1)
  	{
  		cout<<n<<endl;
  		continue;
  	}
  	if(k==0 || k==n || n==0)
  	{
  		cout<<"1"<<endl;
  		continue;
	}
  	if(k>n/2)
  	{
  		k=n-k;
  	}
  	ans=1;
  	ull div=1;
  	ull num,den,g;
  	
  	for(ull i=0;i<k;i++)
  	{
  		if(ans%(i+1)==0)
  		{
  			ans/=(i+1);
  			ans*=(n-i);
  		}
  		else if( (n-i)%(i+1)==0)
  		{
  			ans*= ((n-1)/(i+1));
		}
		/*
  		num=(n-i);
  		den=(i+1);
  		g=gcd(num,den);
  		num/=g;
  		den/=g;
  		top.pb(num);
  		if(den!=1)bot.pb(den);*/
  		
  	}
  	/*
  	for(int i=0;i<bot.size();i++)
  	{
  		for(int j=0;j<top.size();j++)
  		{
  			if(top[j]%bot[i]==0)
  			{
  				top[j]/=bot[i];
  				break;
  			}
  		}
  	}
  	for(int i=0;i<top.size();i++)
  		ans*=top[i];
  	*/
  	cout<<ans<<endl;
  	
  }
 	
 	
}
