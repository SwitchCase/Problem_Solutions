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
 
#define EPS 1e-8 
 
 
 	int G,W;
 	ll M;
ll damage(ll x)
{
	return ((M-G*x)/W) *x;
} 

ll warr(ll x)
{
	return (M-G*x)/W;
}
int main(int argc,char** args)
{
  int i,j,k;
 	int N;
 	scanf("%d",&N);
 	while(N--)
 	{
 		scanf("%d %d %lld",&G,&W,&M);
 		ll dam=damage((ll)(M/(2*G)));
 		ll w= warr((ll)(M/(2*G)));
 		ll w1,dam1;
 		ll ans=M/(2*G);
 		cerr<<"ORIG "<<dam<<" "<<w<<endl;
 		for(int i=-W+1;i<W;i++)
 		{
 			dam1=damage((ll)((M-i)/(2*G)));
 			w1=warr((ll)((M-i)/(2*G)));
 			cerr<<dam1<<" "<<w1<<endl;
 			if(dam1>dam)
 			{
 				
 				dam=dam1;
 				w=w1;
 				ans=(ll)((M-i)/(2*G));
			}
			else if(dam1==dam)
			{
				if(w1>w)
				{
					w=w1;
					ans=(ll)((M-i)/(2*G));
				}
			}
 			
		}
		cerr<<"ENDDDDDDDDDDD"<<endl;
		cout<<ans<<endl;
 		
 		
 		
 		
 		
	}
 	
}
