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
 
 
#define MOD 1051962371

int main(int argc,char** args)
{

	int i,j,k;
	int g,c,n;
	scanf("%d",&n);
	ll der[110];
	ll nCr[105][105]={0};
	der[0]=1;
	der[1]=0;
	for(i=2;i<110;i++)
	{
		der[i]= (ll)(i-1)*(der[i-1]+der[i-2]);
		der[i]%=MOD;
	}	
	nCr[1][0]=nCr[1][1]=1;
	for(i=2;i<105;i++)
	{
		nCr[i][0]=1;
		for(j=1;j<=i;j++)
		{
			nCr[i][j]= nCr[i-1][j-1] + nCr[i-1][j];
			nCr[i][j]%=MOD;
		}
	}
	while(n--)
	{
		scanf("%d %d",&g,&c);
		ll ans =1;
		ll cc,d;
		FORS(i,2,g-c+1)
		{
			ans+= (nCr[g][i] * der[i])%MOD;
			ans%=MOD;			
		}
		cout<<ans<<endl;
	}
	
 	
 	
}
