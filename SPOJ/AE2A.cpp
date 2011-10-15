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
  

int solve(int n,int k) {

	if(k<n || (k==n && n>=3) || k>6*n)return 0;
	if(n==1 && k>6)return 0;
	else if(n==1) return 16;
	ld ans=1;
	int M=k-n;
	int N=n-2;
	
	for(int i=0;i<N+1;i++) {
		ans *= (1.0*(N+M+1-i)/(i+1));
		if(n--) ans/=6.0;
	}
	while(n--)ans/=6.0;
	return (int)(ans*100);
	
}

int main(int argc,char** args)
{
	int T;
	scanf("%d",&T);
	int n,k;
	
	while(T--) {
		scanf("%d%d",&n,&k);
		printf("%d\n",solve(n,k));
	}
 	
 	
}
