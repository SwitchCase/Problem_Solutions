
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


int test10032()
{
	freopen("in1","w",stdout);
	int test=100;
	cout<<test<<endl<<endl;
	while(test--)
	{
		int n=rand()%101;
		if(n==0)n=2;
		cout<<n<<endl;
		FOR(i,n)
		{
			int a=rand()%450;
			if(a==0)a=2;
			cout<<a<<endl;
		}
		cout<<endl;
	}
	return 1;
}

int test10754()
{
	freopen("10754","w",stdout);
	int t=20;
	cout<<t<<endl;
	while(t--)
	{
		int k=rand()%10 + 16;
		int m=rand();
		int n=rand();
		if(m<0)m*=-1;
		if(n<0)n*=-1;
		cout<<k<<" "<<m<<" "<<n<<endl;
		FOR(i,k+1)
		{
			cout<<rand() *(rand()%2?-1:1)<<" ";
		}
		cout<<endl;
		FOR(i,k)cout<<rand()*(rand()%2?-1:1)<<" ";
		cout<<endl;
		cout<<endl;
		
	}
}

int main()
{	
	return test10754();
	return test10032();
	freopen("in1","w",stdout);
	int n=10;
	int ww=21;
	int used[26]={0};
	int edge[26][26];
	FOR(i,n)
	{	
		FOR(j,26)used[j]=0;
		FOR(k,26)
		{
			FOR(kk,26)edge[k][kk]=0;
			edge[k][k]=1;
		}
		string charset="";
		int v=rand()%26;
		if(v<2)v=4;
		char r;
		FOR(j,v)
		{
			r= 'A' + (rand()%26);
				cerr<<"LOOKING FOR r"<<endl;

			while(used['A'-r]!=0)
			{
				r-='A';
				r++;
				r%=26;
				r+='A';
				cerr<<"CHECKING "<<r<<" = "<<used['A'-r]<<endl;
			cerr<<v<<"  "<<j<<endl;			
			}
			cerr<<"FOUND r = "<<r<<endl;
			used['A'-r]=1;
			charset+=r;
		}
		cout<<v<<endl;
		int e=rand()%(v*(v-1));
		cout<<e<<endl;
		int ite=rand()%4;
		if(ite<1)ite=1;
		
		FOR(j,ite)
		{
			cout<<charset[rand()%v];
		}
		cout<<endl;
		FOR(j,e)
		{
			char a,b;
			int ia,ib;
			ia=rand()%v;
			ib=rand()%v;
			//cerr<<"LOOKIN FOR EDGE "<<endl;
			while(edge[ia][ib]==1)
			{
				ia++;
				i%=v;
				ib=rand()%v;
				
			}
			//cerr<<"FOUND IT "<<endl;
			a=charset[ia];
			b=charset[ib];
			if(a>'Z' || a<'A')a='B';
			if(b>'Z' || b<'A')b='C';
			cout<<a<<b<<endl;
			
		}
		cout<<endl;
		cerr<<"TEST "<<i<<endl;
		cerr<<"CHARSET "<<charset<<endl;
	}
}
