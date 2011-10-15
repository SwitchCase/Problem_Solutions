
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
typedef pair<int,int> ii;

string bin(int n)
{
	string ans="";
	while(n)
	{
		if(n&1)ans="1"+ans;
		else ans="0"+ans;
		n>>=1;
	}
	return ans;
}

int main()
{

	int n;
	string q;
	cin>>q;
	//reverse(q.begin(),q.end());
	n=0;
	FOR(i,q.size())
	{
		n<<=1;
		n+= (q[i]=='1'?1:0);
		
	}
	int s=0,f=0;
	int t=n;
	string ans="";
	cout<<"INP BIN "<<bin(n)<<endl;
	int c=0;
	while(c<q.size())
	{
		if(q[c]=='1')
		{
			s++;
			f=1;
		}
		else
		{
			s=0;
			f=0;
		}
		ans+= (q[c]=='1'?"1":"0");
		
		if(s==5)
		{
			ans+="0";
			s=0;
		}
		c++;
		
	}
	//cout<<"OUT BIN "<<bin(ans)<<endl;
	cout<<ans<<endl;
}
