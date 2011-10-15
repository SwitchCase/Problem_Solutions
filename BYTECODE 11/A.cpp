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
#define FORS(i,a,n) for(i=a;i<n;i++)
#define ERR(x) cerr<<#x<<" "<<x<<endl
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define SORT(x) sort(x.begin(),x.end());
#define SEARCH(x,v) binary_search(x.begin(),x.end(),v)
vector<ll> arrx,arry,xpy,xmy,chk;
int main(int argc,char** args)
{
	int i,j,k;
 	int t;
 	ll tx,ty,fx,fy,xm,xp;
 	scanf("%d",&t);
 	while(t--) {
 		arrx.clear();
 		arry.clear();
 		xpy.clear();
 		xmy.clear();
 		chk.clear();
 		scanf("%lld %lld",&fx,&fy);
 		scanf("%lld %lld",&tx,&ty);
 		xm=fx+fy;
 		xp=fx-fy;
 		if(tx<ty)swap(tx,ty);
 		if(fx < fy) swap(fx,fy);
 		if(fx > tx) {
 			swap(tx,fx);swap(ty,fy);
 		}
 		ll k;
 		for(int i=0;i<=63;i++) {
 			k=(1ll<<i);
 			arrx.pb( fx*k);
 			arrx.pb(-fx*k);
 			arry.pb(fy*k);
 			arry.pb(-fy*k);
 			xpy.pb(xp * k);
 			xpy.pb(-xp * k);
 			xmy.pb(xm *k);
			xmy.pb(-xm *k);
 		}
 		
 		FOR(i,arrx.size()) {
 			FOR(j,arry.size()) {
 				chk.pb(arrx[i] + arry[j]);
 				chk.pb(arrx[i] - arry[j]);
 				chk.pb(arry[j] - arrx[i]); 				
 			}
		}
 		SORT(arrx);
 		SORT(arry);
 		SORT(xpy);
 		SORT(xmy);
 		SORT(chk);
		int txf=0,tyf=0;
		
		if(SEARCH(arrx,tx) || SEARCH(arry,tx) || SEARCH(xpy,tx) || SEARCH(xmy,tx) || SEARCH(chk,tx))txf=1;
		if(SEARCH(arrx,ty) || SEARCH(arry,ty) || SEARCH(xpy,ty) || SEARCH(xmy,ty) || SEARCH(chk,ty))tyf=1;		 		
		if(txf && tyf)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
 		
 	}
 	
}
