// <-------------------[sWitCHcAsE]---------------------->
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<vector>
#include<map>
#include<cstring>
#include<cassert>
#include<queue>

#define FOR(i,n) for(i=0;i<n;i++)
#define FORS(i,a,n) for(i=a;i<n;i++)
#define ERR(x) cerr<<#x<<" "<<x<<endl
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
typedef long double ld;
 
#define MAX 1000005
#define ITMS 1000000

struct good{
	int w;
	int p;
};

good arr[ITMS];
int dp[MAX];

int gcd(int a,int b)
{
	if(b==0)return a;
	else return gcd(b,a%b);
}
int main(int argc,char** args)
{
	freopen(args[1],"r",stdin);
	int i,j,k,p,w;
	int n;
	scanf("%d",&n); 	
	char label[1000];
	int c=0;
	int sum=0;
	//assert(30000001n < MAX/2);
	int large=0;
	//int g=n;
 	while(scanf("%s",label)!=EOF)
 	{
 		scanf("%d %d",&w,&p);
 		arr[c].w=w;
 		arr[c++].p=p;
 		sum+=w;
 		if(large<w)large=w;
 		//g=gcd(g,w);
 	}
 	
 	

 
 	//cerr<<"GCD "<<g<<endl;
	FOR(i,n+large+1)dp[i]=100000000;
 	dp[0]=0;
 	
 	//FOR(i,c)dp[arr[i].w]=arr[i].p;
 	FOR(i,c)
 	{
 		good curr=arr[i];
 		for(k=arr[i].w;k<=n+large;k++)
 		{
 			if( dp[k-curr.w]+curr.p < dp[k])
 			{
 				assert(dp[k-curr.w]+curr.p >=0);
 				dp[k]=dp[k-curr.w]+curr.p;
 			}
 		}
 	}
 	int m=(1<<29);
 	
 	for(i=n;i<=n+large;i++)
 	{
 		//if(dp[i]<100000000)cerr<<"DP "<<i<<" "<<dp[i]<<endl;
 		if(m>dp[i]){m=dp[i];p=i;}
 	}
 	printf("%d\n",m);

}
