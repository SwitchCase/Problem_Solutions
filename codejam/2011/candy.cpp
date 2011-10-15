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
	int t;
	scanf("%d",&t);
	int kase=1;
	int mn=9999999,sum=0,check=0,n,num;
	while(kase<=t) {
		printf("Case #%d: ",kase);
		kase++;
		mn=9999999;
		sum=0;
		check=0;
		scanf("%d",&n);
		while(n--) {
			scanf("%d",&num);
			mn=(mn>num)?num:mn;
			check^=num;
			sum+=num;
		}
		if(check)printf("NO\n");
		else printf("%d\n",sum-mn);
	}
	 	
 	
}
