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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define FOR(i,a) for(int i=0;i<a;i++)
#define FORS(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a) for(int i=a;i>=0;i--)
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define MAX2(a,b) (a)<(b)?(b):(a)
#define LEN(s) strlen(s)
#define tests(tc) int tc;scanf("%d",&tc);while(tc--)
#define TEN(n) (long long)pow(10LL,n)
typedef long long ll;
typedef unsigned long long ull;
inline int digitsIn(ll n){int ans=0;while(n){n/=10;ans++;}return ans;}


using namespace std;

int dp[10000000];


ll fun(int q)
{
	if(q==0)return 0;
	else if(q<10000000){
		if(dp[q])return dp[q];
		else return dp[q]= MAX2(q,fun(q/2)+fun(q/4)+fun(q/3));}
	else return MAX2(q,fun(q/2)+fun(q/4)+fun(q/3));

}
int main()
{
	memset(dp,0,sizeof dp);
	
		int q;
		while(scanf("%d",&q)!=EOF)
		printf("%lld\n",fun(q));
	
}
