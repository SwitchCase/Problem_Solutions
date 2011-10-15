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
typedef long long ll;
typedef long double ld;
 
int main(int argc,char** args)
{
	int i,j,k;
	int T;scanf("%d",&T);
	while(T--)
	{	
		ll n;
		scanf("%Ld",&n);
		if(n==1)cout<<"0 0"<<endl;
		ll part1=0ll;
		if(n%2==0)
			part1=(((n/2)%MOD)*((n+1)%MOD))%MOD;
		else 
			part1=((n%MOD)*((n+1)/2 %MOD))%MOD;
		part1-=1;
		part1=(part1+MOD)%MOD;
		
		
		
	} 	
 	
}
