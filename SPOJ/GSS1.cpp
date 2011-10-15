
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
#define LEN(s) strlen(s)
#define tests(tc) int tc;scanf("%d",&tc);while(tc--)
#define TEN(n) (long long)pow(10LL,n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

inline int digitsIn(ll n){int ans=0;while(n){n/=10;ans++;}return ans;}
using namespace std;
int arr[50001];
int N;
int rminq[50001][17];
int rmaxq[50001][17];
int c[50005];
int l[50005];
int p[50005];
int m[50005];

void preProcessRMinQ(int inp[],int n)
{
	FOR(i,n)
	{
		
		rminq[i][0]=i;
		//cout<<"1: "<<i<<" , 0 = "<<i<<endl;
	}
	//cout<<"2::::"<<endl;
	for(int j=1; (1<<j) <=n;j++)
	{
		for(int i=0;i+(1<<(j-1))-1 < n;i++)
		{
			if(inp[rminq[i][j-1]]<=inp[rminq[i+(1<<(j-1))-1][j-1]])
				rminq[i][j]=rminq[i][j-1];
			else rminq[i][j]=rminq[i+(1<<(j-1))-1][j-1];
	//		cout<<rminq[i][j]<<" ";
		}
	//	cout<<endl;
	}
	
}

int RMinQ(int inp[],int a,int b)
{
	if(a==b)return a;
	int j= log10(b-a+1)/log10(2);
	return inp[rminq[a][j]]<inp[rminq[b- (1<<j)+1][j]]?rminq[a][j]:rminq[b- (1<<j)+1][j];
}
void preProcessRMaxQ(int inp[],int n)
{
	
	FOR(i,n)
	{
		rmaxq[i][0]=i;
	}
	for(int j=1; (1<<j) <=n;j++)
	{
		for(int i=0;i+(1<<(j-1))-1 < n;i++)
		{
			if(inp[rmaxq[i][j-1]]>=inp[rmaxq[i+(1<<(j-1))-1][j-1]])
				rmaxq[i][j]=rmaxq[i][j-1];
			else rmaxq[i][j]=rmaxq[i+(1<<(j-1))-1][j-1];
		}
	}
}


int RMaxQ(int inp[],int a,int b)
{
	if(a==b)return a;
	int j= log10(b-a+1)/log10(2);
	return inp[rmaxq[a][j]]>inp[rmaxq[b- (1<<j)+1][j]]?rmaxq[a][j]:rmaxq[b- (1<<j)+1][j];
}

void GSSPreProcess()
{
	c[0]=0;
	FORS(j,1,N)
	{
		c[j]=c[j-1]+arr[j];
		l[j]=j-1;
		while( c[l[j]] < c[j] && l[j]>0)l[j]=l[l[j]];
	}
}


void GSSPreProcess2()
{
	preProcessRMinQ(c,N);
	FOR(j,N+1)
	{
		p[j]=RMinQ(c,l[j],j-1)+1;
		m[j]=c[j]-c[p[j]-1];
				
	}
}

void GSS()
{
	GSSPreProcess();
	GSSPreProcess2();
	preProcessRMaxQ(m,N);
}

int SUM(int a,int b)
{
	int res=0;
	FORS(i,a,b+1)
		res+=arr[i];
	return res;
}

int doQuery(int a,int b)
{
	int r=RMaxQ(m,a,b);
	if(p[r]<a)
	{
		int r1=RMinQ(c,a-1,r-1)+1;
		int r2=RMaxQ(m,r+1,b);
		if(c[r]-c[r1-1]<m[r2])
		{
			return SUM(p[r2],r2);
		}
		else return SUM(r1,r);
	}
	else return SUM(p[r],r);
}
int main()
{
	
	scanf("%d",&N);
	FOR(i,N)scanf("%d",&arr[i]);
	int qi,qj;
	
		//GSS();
		preProcessRMaxQ(arr,N);
	tests(tc)
	{
		scanf("%d%d",&qi,&qj);
		qi--;qj--;
		if(qj<qi)swap(qi,qj);
		cout<<"ANS :"<<qi<<" , "<<qj<<" = "<<arr[RMaxQ(arr,qi,qj)-1]<<endl;
	}
}
