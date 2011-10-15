
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
typedef pair<int,int> ii;
#define INF 1000000000
//int dp[102][450001][2];
int dp[102][45001];
int use[102][45001];
int cnt[102][45001];
VI vic[102][45001];
int arr[102];
int sum;
int half;
int n;

/*
int rec(int wt,int k,int team1,int whichTeam)
{	

	//cerr<<"CALLED ST1 "<<wt<<" "<<k<<" "<<team1<<" "<<whichTeam<<endl;
	if(wt<0)return INF;
	if((team1>((n+1)/2))||(k-team1>(n+1)/2))return INF+1;
//	if(wt>half)return INF+2;
	if(k>n)return INF+3;
	if(k==n)return wt;	
	
	if(dp[k][wt][whichTeam]!=-1)return dp[k][wt][whichTeam];
	int k1=rec(wt+arr[k],k+1,(whichTeam?team1:team1+1),whichTeam);
	//if(k1==0)return dp[k][wt][whichTeam]=0;
	int k2=rec(abs(wt-arr[k]),k+1,(whichTeam?team1+1:team1), (wt<arr[k]?!whichTeam:whichTeam));
	//cerr<<"CALLED inside "<<wt<<" "<<k<<" "<<team1<<" "<<whichTeam<<" RETURNED : "<<k1<<"  "<<k2<<endl;
	if(k1<INF && k2<INF)
	{
		
		if(k1<k2)
		{
			//cerr<<"CALLED inside "<<wt<<" "<<k<<" "<<team1<<" "<<whichTeam<<" RETURNED : "<<k1<<endl;
			return dp[k][wt][whichTeam]=k1;
		}
		else
		{
	//	cerr<<"CALLED inside "<<wt<<" "<<k<<" "<<team1<<" "<<whichTeam<<" RETURNED : "<<k2<<endl;
			 return dp[k][wt][whichTeam]=k2;
		}
	}
	else
	{
		if(k1<INF)return dp[k][wt][whichTeam]=k1;
		else return dp[k][wt][whichTeam]=k2;
	}
	
}
*/
int main()
{
	tests(tc)
	{
		scanf("%d",&n);
		//INIT(dp,0);
		sum=0;
		half=0;
		FOR(i,n){scanf("%d",&arr[i]);sum+=arr[i];}
		if(sum%2==0)half=sum/2;
		else half=(sum+1)/2;
		sort(arr,arr+n);
		//reverse(arr,arr+n);
		INIT(dp[0],0);
		INIT(cnt[0],0);
	//INIT(use,0);
		dp[0][arr[0]]=1;
		use[1][arr[0]]=1;
		cnt[0][arr[0]]=1;
		dp[0][0]=1;
		FOR(i,102)dp[i][0]=1;
		INIT(use[(n+1)/2],0);
		INIT(use[n/2],0);
		FOR(i,45001)vic[0][i].clear();
		int s=arr[0];
		FORS(i,1,n)
		{	
			s+=arr[i];
			//dp[i][arr[i]]=1;
			FORS(j,1,sum+1)
			{
				//cerr<<"----------["<<i<<" "<<j<<"]-------------"<<endl;
				dp[i][j]=0;
				cnt[i][j]=0;
				vic[i][j].clear();
				if(dp[i-1][j]!=0)
				{
					dp[i][j]=dp[i-1][j];
					vic[i][j]=vic[i-1][j];
					cnt[i][j]=cnt[i-1][j];
					use[cnt[i][j]][j]=1;
					//cerr<<"1 : dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
				}
				if(j>=arr[i] && dp[i-1][j-arr[i]]>0)
				{
					//if(j==arr[i])cerr<<j<<" = "<<arr[i]<<endl;
					/*if(dp[i][j]!=0)
					dp[i][j]=max(dp[i][j],dp[i-1][j-arr[i]]+1);
					else dp[i][j]=dp[i-1][j-arr[i]]+1;*/
					dp[i][j]=dp[i-1][j-arr[i]];
					
				/*	int m=cnt[i-1][j-arr[i]];
					
						use[m+1][j]=1;
					if(cnt[i][j]!=0)
					{
						use[cnt[i][j]][j]=1;	
							
					}*/
					
					//cerr<<"2 : dp["<<i<<"]["<<j<<"]= "<<dp[i][j]<<" "<<"use["<<(m+1)<<"]["<<j<<"]= 1 cnt["<<i<<"]["<<j<<"]= "<<cnt[i][j]<<" < "<<(cnt[i-1][j-arr[i]]+1)<<endl;
					//if(cnt[i-1][j-arr[i]]+1 <=(n+1)/2)
						vic[i][j].pb(cnt[i-1][j-arr[i]]+1);
						FOR(m,vic[i][j].size())
						{
							use[vic[i][j][m]][j]=1;
							cerr<<"PB: "<<i<<" "<<j<<" "<<vic[i][j][m]<<" ";
						}
						cerr<<endl;
						
						cnt[i][j]=cnt[i-1][j-arr[i]]+1;
					
				}
				/*
				if(dp[i][j]!=0)
				{
					//cerr<<"ERR "<<i<<" "<<j<<" "<<"dp = "<<dp[i][j]<<" "<<dp[i-1][j]<<" ";
					if(j>arr[i])cerr<<dp[i][j-arr[i]];
					cerr<<endl;
				}*/
			}
		}
		
		/*FOR(i,sum+1)
		{
			if(dp[n-1][i]==n/2 || dp[n-1][i]==(n+1)/2)
			{
				cerr<<i<<" : "<<dp[n-1][i]<<endl;
			}
		}*/
		int minm=half;
		int found=false;
		for(int i=0;i<=half;i++)
		{
			if(dp[n-1][i]==1)
			{
				//cerr<<i<<" : "<<cnt[n-1][i]<<" "<<use[n/2][i]<<" "<<use[(n+1)/2][i]<<endl;
			}
			//if(dp[n-1][i]==(n+1)/2 || dp[n-1][i]==n/2)
			if(dp[n-1][i]==1 && (use[(n+1)/2][i]==1 || use[n/2][i]==1))
				if(minm>half-i)
				{
					minm=half-i;
					found=true;
				}
			//if(dp[n-1][i]!=0 && (use[(n+1)/2][i]==1 || use[n/2][i]==1))cerr<<i<<" : "<<dp[n-1][i]<<endl;
		}
		int ans=2*minm;	
		int a=(sum+ans)/2;
		//cerr<<"ANS "<<ans<<endl;
	/*	if(!found)
		{
			FORS(i,half+1,s+1)
			{
				if(dp[n-1][i]==n/2 || dp[n-1][i]==(n+1)/2)
				{
					a=i;
					break;
				}
			}
		}
		*/
		
		int b=sum-a;
		if(a>b)swap(a,b);
		cout<<a<<" "<<b<<endl;
		if(tc!=0)cout<<endl;
	}
}
