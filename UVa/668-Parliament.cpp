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
 
int main(int argc,char** args) {
	int comb[1001];
	comb[0]=comb[1]=comb[2]=1;
	for(int i=3;i<1001;i++)comb[i]=comb[i-1] + i-1;
	int t,N,m,l;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&N);
		m= (sqrt(8*N+1)-1)/2;
		l=N-comb[m+1];
		if(l==m) {
			for(int i=2;i<m+1;i++)printf("%d ",i);
			printf("%d\n",m+1);
		}
		else if(l==m-1) {
			for(int i=3;i<=m;i++)printf("%d ",i);
			printf("%d\n",m+2);
		}
		else {
			for(int i=2;i<m+1;i++) {
				if(i==m-l)continue;
				printf("%d ",i);
			}
			printf("%d\n",m+1);
		}
		if(t!=0)printf("\n");
	}
}
