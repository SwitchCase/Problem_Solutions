
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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

using namespace std;
inline VS split(string s,char* tok){VS vs;char *pch;char *q= (char*)s.c_str();	pch=strtok(q," ");	while(pch !=NULL){vs.pb(string(pch));pch=strtok(NULL,tok);}return vs;}
inline int digitsIn(ll n){int ans=0;while(n){n/=10;ans++;}return ans;}

int arr[13];
map<string,int> mp;
string dp[13][1001];
int t,n;
string itoa(int n)
{
	string ans="";
	while(n)
	{
		char c= '0'+n%10;
		ans= c + ans;
		n/=10;
	}
	return ans;
}
int main()
{
	
	while(1)
	{
		scanf("%d%d",&t,&n);
		if(n==0)break;
		FOR(i,n)scanf("%d",&arr[i]);
		int max=1<<n;
		//max--;
		int temp;
		int sum=0,m;
		string curr="";
		FOR(i,max)
		{
			temp=i;
			curr="";
			m=0;
			sum=0;
			while(temp)
			{
				if(temp&1)
				{
					curr+= (itoa(arr[m]))+ "+";
					sum+=arr[m];
				}
				m++;
				temp>>=1;
			}
			if(sum==t)
			{
				mp[curr]=1;
			}
		}
		map<string,int>::reverse_iterator it= mp.rbegin();
		cout<<"Sums of "<<t<<":"<<endl;
		int v=0;
		for(;it!=mp.rend();it++)
		{
			v++;
			string t=(*it).first;
			t=t.substr(0,t.size()-1);
			cout<<t<<endl;
		}
		if(v==0)cout<<"NONE"<<endl;
		mp.clear();
		
	}
}
