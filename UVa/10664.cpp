
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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

using namespace std;
inline VS split(string s,char* tok){VS vs;char *pch;char *q= (char*)s.c_str();	pch=strtok(q," ");	while(pch !=NULL){vs.pb(string(pch));pch=strtok(NULL,tok);}return vs;}
inline int digitsIn(ll n){int ans=0;while(n){n/=10;ans++;}return ans;}


#define INF 10000000
int arr[21];
int dp[21][501];
int n;
int sum;
int req;


int rec(int wt,int k)
{	
	if(wt<0)return INF;
	if(k>n)return INF;
	if(k==n && wt!=0)return INF;
	if(wt==0 && k==n)return 0;
	if(dp[k][wt]!=-1)return dp[k][wt];
	int k1=rec(wt+arr[k],k+1);
	int k2=rec(abs(wt-arr[k]),k+1);
	if(k1<INF && k2<INF){
	return dp[k][wt]=MAX2(k1,k2);}
	 return dp[k][wt]=MIN2(k1,k2);
	
}
int main()
{
	
	tests(tc)
	{
		
		fflush(stdin);
		memset(dp,-1,sizeof dp);
		char s1[1000];
		cin.getline(s1,1000);
		//cout<<"S: "<<s1<<endl;
		string s=string(s1);
		VS temp=split(s," ");
		n=0;
		sum=0;
		req=0;
		FOR(i,temp.size()){ arr[i]= atoi(temp[i].c_str());sum+=arr[i];n++;}
		if(sum&1)
		{
			printf("NO\n");
			continue;
		}
		sort(arr,arr+n);
		reverse(arr,arr+n);
		int ans=rec(0,0);
		if(ans==0)printf("YES\n");
		else printf("NO\n");
		
		
	}
}
