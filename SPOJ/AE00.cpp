//<----------[sWitCHcAsE]----------->

#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cstdlib>
#include<cstring>

using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

int main() {
	int n,ans=0;
	scanf("%d",&n);
	for(int j=1;j<=n;j++)
	for(int i=1;i*i<=j;i++) {
		if(!(j%i))ans++;
	}
	printf("%d\n",ans);
}
