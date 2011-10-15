
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

typedef pair<int,int> ii;
string s1,s2;
ii dp[31][31];
int done[31][31];
ii fun(int i,int j)
{
	if(i>=s1.size())return make_pair(s2.size()-j,1);
	else if(j>=s2.size())return make_pair(s1.size()-i,1);
	if(done[i][j])return dp[i][j];
	else
	{
		done[i][j]=1;
		if(s1[i]==s2[j])
		{
			ii ret=fun(i+1,j+1);
			ret.first+=1;
			//ret.second+=2;
			return dp[i][j]=ret;
		}
		else
		{
			ii f1=fun(i+1,j);
			ii f2=fun(i,j+1);
			if(f1.first == f2.first)return dp[i][j]=make_pair(f1.first+1,f1.second+f2.second);
			else
			{
				if(f1.first<f2.first)return dp[i][j]=make_pair(f1.first+1,f1.second);
				else return dp[i][j]=make_pair(f2.first+1,f2.second);
			}
		}
	}
}

int main()
{
	char buff1[100],buff2[100];
	int kase=1;
	tests(tc)
	{
		INIT(done,0);
		cin.getline(buff1,100);
		cin.getline(buff2,100);
		s1=string(buff1);
		s2=string(buff2);
		ii ans=fun(0,0);
		cout<<"Case #"<<kase<<": ";
		cout<<ans.first<<" "<<ans.second<<endl;
		kase++;
	}
}
