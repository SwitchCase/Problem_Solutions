
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
#define tests(tc) int tc;scanf("%d%*c",&tc);while(tc--)
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

ll dp[10001];
ll arr[10001];
int prev[10001];
int main()
{
	string s="";
	char buff[10001];
	bool f=true;
	tests(tc)
	{
		if(f)
		{
			cin.getline(buff,10001);
			s=string(buff);
			//cerr<<"IP "<<"\""<<s<<"\""<<endl;
			f=false;
		}
		else
		{
			cout<<endl;
		}
		int n=0;
		while(1)
		{
			cin.getline(buff,10001);
			s=string(buff);
			//cerr<<"IP "<<"\""<<s<<"\""<<endl;
			if(s=="")		
			{
				break;
			}
			arr[n++]=atoi(s.c_str());
		}
		INIT(dp,sizeof(ll) * (n+1));
		FOR(i,n)
		{
			dp[i]=1;
			prev[i]=i;
			FOR(j,i)
			{
				if(arr[i] > arr[j])
				{
					if(dp[i]<dp[j]+1)
					{
						dp[i]=dp[j]+1;
						prev[i]=j;
					}
					
				}
			}
		}
		ll maxm=0LL;
		int ind=0;
		FOR(i,n)if(dp[i]>maxm){maxm=dp[i];ind=i;}
		cout<<"Max hits: "<<maxm<<endl;
		VI ans;
		ans.pb(arr[ind]);
		int f=1;
		int tind;
		while(f)
		{
			tind=ind;
			ind=prev[ind];
			if(tind==ind)break;
			ans.pb(arr[ind]);
			
		}
		VI::reverse_iterator it=ans.rbegin();
		for(;it!=ans.rend();it++)
		{
			cout<<(*it)<<endl;
		}
		
	}
}
