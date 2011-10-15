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
typedef long long ll;


template <class T>inline void swap(T &a,T &b)
{
	T t=a;a=b;b=t;
}

using namespace std;

int main()
{
	ll dp[51];
	dp[0]=0;
	dp[1]=1;dp[2]=2;dp[3]=3;
	for(int i=4;i<51;i++)dp[i]=(dp[i-1]+dp[i-2]);
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(!n)break;
		cout<<dp[n]<<endl;	
	}
}
