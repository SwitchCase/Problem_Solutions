
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
string getS(int n)
{
	string a="0000000000000";
	FOR(i,13)
	{
		if((n&(1<<i))>0)
		a[12-i]='1';
	}
	return a;
}

int main()
{
	freopen("./in2","w",stdout);
	int N=100;
	cout<<N<<endl;
	while(N--)
	{
		int n,l,k;
		char st[]="qwertyuioplkjhgfdsazxcvbnm";
		n=rand()%151;
		l=rand()%151;
		k=rand()%501;
		printf("%d %d %d\n",n,l,k);
		cout<<endl;
		FOR(i,n)
		{
			FOR(j,l)
			{
				char c=st[rand()%26];
				printf("%c",c);
			}
			cout<<endl;
		}
		cout<<endl;
	}
}
