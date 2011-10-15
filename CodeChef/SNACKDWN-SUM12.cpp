
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

ll matrix[2][2]={{1LL,1LL},{1LL,0LL}};

void square(ll mat[2][2],ll m)
{
	int temp[2][2];
	FOR(i,2)FOR(j,2)temp[i][j]=mat[i][j];
	mat[0][0]=(((temp[0][0]%m)*temp[0][0])%m+ ((temp[0][1]%m)*temp[1][0])%m)%m;
	mat[0][1]=(((temp[0][0]%m)*temp[0][1] )%m+ ((temp[0][1]%m)* temp[1][1]))%m;
	mat[1][0]=(((temp[1][0]%m)*temp[0][0])%m+ ( (temp[1][1]%m)*temp[1][0]))%m;
	mat[1][1]=(((temp[1][0]%m)*temp[0][1] )%m+ ((temp[1][1]%m)* temp[1][1]))%m;

}

void multiply(ll mat[2][2], ll mat2[2][2],ll m)
{
	int temp[2][2];
	FOR(i,2)FOR(j,2)temp[i][j]=mat[i][j];
	mat[0][0]=(((temp[0][0]%m)*mat2[0][0])%m+ ( (temp[0][1]%m)*mat2[1][0]))%m;
	mat[0][1]=(((temp[0][0]%m)*mat2[0][1] )%m+ ( (temp[0][1]%m)* mat2[1][1]))%m;
	mat[1][0]=(((temp[1][0]%m)*mat2[0][0])%m+ ( (temp[1][1]%m)*mat2[1][0]))%m;
	mat[1][1]=(((temp[1][0]%m)*mat2[0][1] )%m+ ((temp[1][1]%m)* mat2[1][1]))%m;
}

void fast_exp(ll n,ll m)
{
	ll d[2][2]={{1LL,0LL},{0LL,1LL}};
	FORR(i,31)
	{
		square(d,m);
	//	cerr<<" MAT AFTER SQUARING "<<endl;
		//FOR(i,2)FOR(j,2)cerr<<matrix[i][j]<<" ";
	//	cerr<<endl;
		if(n & (1<<i))
		{
			multiply(d,matrix,m);
			//cerr<<" D AFTER MULTIPLY "<<endl;
		//	FOR(i,2)FOR(j,2)cerr<<d[i][j]<<" ";
		//cerr<<endl;
		}
		
	}
	FOR(i,2)FOR(j,2)matrix[i][j]=d[i][j];
}

int main()
{
	ll m=1000000007;
	tests(tc)
	{
		ll n;
		
		scanf("%lld",&n);
		n--;
		//cerr<<"M "<<m<<" ";
		matrix[0][0]=1LL;
		matrix[0][1]=1LL;
		matrix[1][0]=1LL;
		matrix[1][1]=0LL;
		
		fast_exp(n,m);
		//FOR(i,2)FOR(j,2)cerr<<matrix[i][j]<<" ";
		//cerr<<endl;
		printf("%lld\n",matrix[0][0]);
	}
}
