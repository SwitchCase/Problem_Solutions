
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
struct tile
{
	int A;
	int B;
	int C;
	int D;
};
tile board[9];
int emp[9];

bool isS(int* emp)
{
	//int emp[9];
	
	bool ans=false;
	for(int i=0;i<3;i+=3)
	{
		if(board[emp[i]].B==board[emp[i+1]].D && board[emp[i+1]].B==board[emp[i+2]].D)
			ans=true;
		else return false;
	}
	for(int i=0;i<6;i++)
	{
		if(board[emp[i]].C==board[emp[i+3]].A)ans=true;
		else return false;
	}
	return ans;
}

int main()
{
	
	int a,b,c,d;
	
	int ka=0;
	tests(tc)
	{
		ka++;
		FOR(i,9)
		{
			scanf("%d %d %d %d",&board[i].A,&board[i].B,&board[i].C,&board[i].D);
			emp[i]=i;
		}
		bool solve=false;
		do{
			solve=isS(emp);
			if(solve)break;
		}while(next_permutation(emp,emp+9));
		if(solve)printf("Case %d: YES\n",ka);
		else printf("Case %d: NO\n",ka);
	}
}
