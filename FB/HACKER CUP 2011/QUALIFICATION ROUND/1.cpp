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
  	int i,j,k,N,n;
 	scanf("%d",&N);
 	while(N--)
 	{
 		int ans=0;
 		ll ii;
 		scanf("%d",&n);
 		for(ii=0;ii*ii<=n;ii++)
 		{
 			ld root=sqrt(n-ii*ii);
 			ll rr=(ll)root;
 			if(rr*rr + ii*ii ==n && ii >= rr)ans++; 
 		}
 		printf("%d\n",ans);
 	}
 	
}
