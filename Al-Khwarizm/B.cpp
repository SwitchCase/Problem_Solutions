
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

#define FOR(i,a) for(int i=0;i<a;i++)
#define FORS(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a) for(int i=a;i>=0;i--)
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define MAX2(a,b) (a)<(b)?(b):(a)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define LEN(s) strlen(s)
#define tests(tc) int tc;scanf("%d",&tc);while(tc--)
#define TEN(n) (long long)pow(10LL,n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

inline int digitsIn(ll n){int ans=0;while(n){n/=10;ans++;}return ans;}
using namespace std;

void get(int a,int b)
{
	int r=a%26;
	if(b< 'Z'-'A'-r)printf("%c\n",'A'+r+b);
	else printf("%c\n",(b-'Z'+'A'+r)%26);
}
int main()
{
	int range[1000];
	range[0]=0;
	FORS(i,1,1000)
	{
		range[i]=range[i-1]+i;
	}
	//cerr<<"DONE"<<endl;
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		N--;
		int nth=upper_bound(range,range+1000,N) - range;
		nth--;
		//cerr<<"RA US "<<range[nth]<<" NTH "<<nth<<endl;
		
		N-=range[nth];
		//if(N<0)cerr<<"ASDS"<<endl;
		if(N==0)get(nth,0);
		else if(N==1)get(0,nth);
		else
		{
			N-=1;
			get(N,nth-N);
		}
		
	}
}
