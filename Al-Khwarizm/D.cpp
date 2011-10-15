
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

struct interval
{
	int A;
	int B;
	int index;
};
interval arr[200001];
interval ind[200001];
int ans[200001];
int look[200001];
bool cmp(struct interval a,struct interval b)
{
	if(a.A<=b.A && a.B>=b.B)return false;
	else return true;
}


void count(int in,int n)
{
	int a=1;
	if(2*in<n)
	{
		look[in]+=1+look[2*in];
	}
	if(2*in-1 <n) look[in]+=1+look[2*in-1];
	else look[in]=0;
}
int main()
{
	int n;
	memset(ans,0,sizeof ans);
	while(scanf("%d",&n)!=EOF)
	{
		FOR(i,n){
			if(scanf("%d %d",&arr[i].A,&arr[i].B)!=EOF)
			{
				arr[i].index=i;
				if(arr[i].A > arr[i].B)
					swap(arr[i].A,arr[i].B);
				ind[i].A=arr[i].A;ind[i].B=arr[i].B;
					
			}
			else return 0;
		}
		make_heap(arr,arr+n,cmp);	
		FORR(i,n-1)count(i,n);
		FOR(i,n)
		{
			ans[arr[i].index]=look[i];
		}
		FOR(i,n)
		{
			printf("%d",ans[i]);
			if(i!=n-1)printf(" ");
		}
		printf("\n");
	}
}
