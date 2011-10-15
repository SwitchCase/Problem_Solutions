
// <-------------------[sWitCHcAsE]---------------------->

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FORS(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a) for(int i=a;i>=0;i--)
#define foreach(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define MAX2(a,b) (a)<(b)?(b):(a)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define LEN(s) strlen(s)
#define tests(tc) int tc;scanf("%d",&tc);while(tc--)
#define TEN(n) (long long)pow(10LL,n)
#define bits __builtin_popcount
#define INIT(arr,val) memset(arr,val,sizeof arr)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

using namespace std;
inline VS split(string s,char* tok){VS vs;char *pch;char *q= (char*)s.c_str();	pch=strtok(q," ");	while(pch !=NULL){vs.pb(string(pch));pch=strtok(NULL,tok);}return vs;}
inline int digitsIn(ll n){int ans=0;while(n){n/=10;ans++;}return ans;}

int arr[101];
ull dp[45005];



int main()
{
	tests(tc)
	{
		int n;
		scanf("%d",&n);
		FOR(i,n)scanf("%d",&arr[i]);
		INIT(dp,0);
		int sum=0;
		FOR(i,n)sum+=arr[i];
		assert(sum<45001);
		
		sort(arr,arr+n);
		dp[0]=1;
		FOR(i,n)
		{
			FORR(j,sum+1)
			{
				if(j>=arr[i])
				{
					if(j==arr[i]){dp[j]|=1;
					//cerr<<"UPD "<<j<<" "<<dp[j]<<endl;
					}
					else if(dp[j-arr[i]]>0)
					{
						dp[j]|=dp[j-arr[i]]<<1;
		//				cerr<<"UPD2 "<<j<<" "<<dp[j]<<" coz "<<dp[j-arr[i]]<<endl;
					}
				}
			}
		}
		int k=n/2;
		int k1=(n+1)/2;
		ull mask1=(1ll<<(k-1)),mask2=(1ll<<(k1-1));
		int ans=0;
	//	cerr<<"MASKS "<<mask1<<"  "<<mask2<<endl;
		FORR(i,sum/2)
		{
			//cerr<<i<<" = "<<dp[i]<<endl;
			if(( (mask1 & dp[i])==mask1 || (mask2 & dp[i])==mask2))
			{
				ans=i;
				break;
			}
		}
		int ans2=sum-ans;
		if(ans>ans2)swap(ans,ans2);
		cout<<ans<<" "<<ans2<<endl;
		if(tc!=0)cout<<endl;
		
		
	}
}
