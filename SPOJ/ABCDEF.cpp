
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
#include <hashtable.h>

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

int arr[101];
int LHS[1000009], RHS[1000009];

int main()
{
	int n;
	scanf("%d",&n);
	FOR(i,n)scanf("%d",&arr[i]);
	int l1=0,l2=0;
	FOR(i,n)
	{
		FOR(j,n)
		{
			FOR(k,n)
			{	
				int temp=arr[i]*arr[j]+arr[k];
				LHS[l1++]=temp;
				//cerr<<":"<<temp<<endl;
				if(arr[i]!=0)
				{
					temp=arr[i]*(arr[j]+arr[k]);
					//cerr<<"::"<<temp<<endl;
					RHS[l2++]=temp;
				}
				//ll temp=arr[i]*arr[j]+arr[k];	
				
			}
		}
	}
	
	
	//cerr<<"SORTING for l= "<<l<<endl;
	sort(LHS,LHS+l1);
	sort(RHS,RHS+l2);
	int i=0,j=0;
	ll ans=0LL;
	int c1=0,c2=0;
	while(i<l1 && j<l2)
	{
		while(LHS[i]!=RHS[j] && i<l1 && j<l2)
		{
			if(LHS[i]<RHS[j])i++;
			else j++;
			
		}
		if(i>=l1 || j>=l2)break;
		c1=0;c2=0;
		while(i+c1<l1 && LHS[i]==LHS[i+c1])c1++;
		while(j+c2<l2 && RHS[j]==RHS[j+c2])c2++;
		i+=c1;j+=c2;
		ans+= (1LL)*c1*c2;
	}
	
	
	printf("%lld\n",ans);
	return 0;
	
}
