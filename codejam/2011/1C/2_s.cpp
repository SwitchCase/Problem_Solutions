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
 
 
int inp[10010]; 
int main(int argc,char** args)
{
	int T;
	scanf("%d",&T);
	int n,l,h;
	FOR(kase,T) {
		scanf("%d%d%d",&n,&l,&h);
		FOR(i,n)scanf("%d",&inp[i]);
		int ans=-1;
		for(int i=l;i<=h;i++) {
			int cnt=0;
			FOR(j,n) {
				if(i%inp[j]==0 || inp[j]%i==0)cnt++;
			}
			if(cnt==n) {
				ans=i;
				break;
			}
		}
		if(ans==-1) {
			cout<<"Case #"<<kase+1<<": NO\n";
		}
		else
			cout<<"Case #"<<kase+1<<": "<<ans<<"\n";
	}
 	
 	
}
