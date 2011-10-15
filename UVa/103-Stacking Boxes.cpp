
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
//#define DEBUG

struct BOX
{
	int a[13];
	int pos;
};

int n,d;
BOX box[32];
int orig[32][12];
int dp[32];
int sol[32];
int change[32];

bool Greater(BOX A, BOX B)
{
	int ans=0;
	int *a=A.a;
	int *b=B.a;
	FOR(i,d)
	{
		if(a[i] > b[i])continue;
		else return false;
	}
	return true;
}
void Swap(BOX *a,BOX *b)
{
	BOX *c=a;
	a=b;b=a;
}

int main()
{
	int ans=0;
	int ind=-1;
	int s=0;		
		
	while(scanf("%d%d",&n,&d)!=EOF)
	{	
		ans=0;
		ind=-1;
		s=0;
		FOR(i,n){
		FOR(j,d)
			scanf("%d",&box[i].a[j]);
		box[i].pos=i;
		}
		FOR(i,n){sort(box[i].a,box[i].a+d);}
		INIT(dp,0);
		FOR(i,n)change[i]=i;
		#ifdef DEBUG
		cerr<<"---------[ BOXES ]---------"<<endl;
		FOR(i,n)
		{
			FOR(j,d)cerr<<box[i].a[j]<<" ";
			cerr<<endl;
		}
		cerr<<endl<<"---------------------"<<endl;
		#endif
		FOR(i,n)
		{
			FORS(j,i+1,n)
			{
				if(Greater(box[i],box[j]))
				{
					BOX a=box[i];
					box[i]=box[j];
					box[j]=a;
				}
			}
		}
		/*
		FOR(i,n)
		{
			int curr=change[i];
			FOR(j,d)
			{
				box[i][j]=orig[curr][j];
			}
		}*/
		//sort(box,box+n,Greater);
		#ifdef DEBUG
		cerr<<"---------------------"<<endl;
		FOR(i,n)cerr<<change[i]<<" ";
		cerr<<endl<<"---------------------"<<endl;
		#endif
		FOR(i,n)
		{
			dp[i]=1;
			sol[i]=i;
			FOR(j,i)
			{
				/*int t=0;
				FOR(k,d)
				{
					if(box[i][k]<box[j][k])
					{
						t=1;break;
					}	
				}*/
				if(Greater(box[i],box[j]))
					if(dp[i]<1+dp[j]){dp[i]=max(dp[i],1+dp[j]);sol[i]=j;}
			}
			if(ans<dp[i]){ans=dp[i];ind=i;}
		}
		#ifdef DEBUG
		cerr<<"-------DP AND SOL-------"<<endl;
		FOR(i,n)
		cerr<<i<<"  "<<dp[i]<<"  sol "<<sol[i]<<endl;
		cerr<<"----------------"<<endl;
		#endif
		printf("%d\n",ans);
 		VI fi;
 		fi.pb(box[ind].pos+1);
 		while(sol[ind]!=ind)
 		{
 			ind=sol[ind];
 			fi.pb(box[ind].pos+1);
 		}
 		reverse(fi.begin(),fi.end());
 		printf("%d",fi[0]);
 		FOR(i,fi.size()-1)
 		printf(" %d",fi[i+1]);
		printf("\n");
	}
}
