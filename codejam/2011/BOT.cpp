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
 
struct item {
	int a;
	char r;
};
item move[150];
int O[100],R[100];
int o,r;

int main(int argc,char** args)
{
	int t,n,kase=1;
	int ans,ot,bt,op,bp,np,nt,pos;
	char rob;
	scanf("%d",&t);
	while(kase<=t) {
		ans=0;
		ot=bt=0;
		op=bp=1;
		
		scanf("%d",&n);
		FOR(i,n) {
			scanf(" %c %d",&rob,&pos);
			if(rob=='O') {
				np=abs(op-pos);//1
				nt=ans-ot; // 0
				if( nt >= np) 
					ans++;
				else 
					ans+= (np-nt+1);	
				op=pos;
				ot=ans;
			}
			else {
				np=abs(bp-pos);
				nt=ans-bt;
				if( nt >= np) 
					ans++;
				else 
					ans+= (np-nt+1);	
				bp=pos;
				bt=ans;
			}
			cerr<<"AFTER "<<rob<<" goes to "<<pos<<" time will be "<<ans<<" wid np= "<<np<<" and nt= "<<nt<<endl;
		}
		//cerr<<endl;
		//FOR(i,n) cerr<<" RO "<<move[i].r<<" "<<move[i].a<<endl;
		
		printf("Case #%d: %d\n",kase,ans);
		kase++;
		
	}
	
 	
 	
}
