
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

char a[61],b[61],c[61];
int la,lb,lc;
int dp[61][61][61];
int MOD=10007;

int f(int,int,int,int);
int g(int i,int j,int k)
{
	if(k==lc)return dp[i][j][k]=1;
	else if(dp[i][j][k]!=-1)return dp[i][j][k];
	return dp[i][j][k]=(f(0,i,j,k)+f(1,i,j,k))%MOD;
}
int dpf[2][61][61][61];
int f(int t,int i,int j,int k)
{
	if(k==lc)return 1;
	if(i>=la && t==0)return 0;
	if(j>=lb && t==1)return 0;
	
	if(dpf[t][i][j][k]!=-1)return dpf[t][i][j][k];
	//if(dp[i][j][k]!=-1)return dp[i][j][k];
	int &ans=dpf[t][i][j][k]=0;
	//int ans=0;
	if(t==0)
	{
		ans=f(0,i+1,j,k)%MOD;
		if(a[i]==c[k])
		{
				
			ans+=f(0,i+1,j,k+1);
			ans%=MOD;
			ans+=f(1,i+1,j,k+1);
			//ans=g(i+1,j,k+1);
			ans%=MOD;
		}
	}
	else
	{
		ans+=f(1,i,j+1,k);
		if(b[j]==c[k])
		{
			ans+=f(1,i,j+1,k);
			ans%=MOD;
			ans+=f(0,i,j+1,k);
			
			//ans+=g(i,j+1,k+1);
			ans%=MOD;
		
		}
	}
	return ans;
	
}
int main()
{
	tests(tc)
	{
		scanf("%s%s%s",a,b,c);
		la=strlen(a);
		lb=strlen(b);
		lc=strlen(c);
		INIT(dp,-1);
		INIT(dpf,-1);
		cout<<(f(0,0,0,0) + f(1,0,0,0))%MOD<<endl;
	}
}
/*

using namespace std;
char s1[61],s2[61],s3[61];
int sz1,sz2,sz3,dp[61][61][61];
int pre1[61][26],pre2[61][26];
int fun(int i,int j,int k){
   //if(sz1-i+sz2-j<sz3-k) return 0;
   if(i>=sz1 || j>=sz2 || k>=sz3)return 0; 
   if(dp[i][j][k]!=-1) return dp[i][j][k];
   dp[i][j][k]=0;
   /*for(int index=i;index<sz1;index++){
      if(s1[index]==s3[k]){
              if(k==sz3-1) dp[i][j][k]=(dp[i][j][k]+1)%10007;
         else
            dp[i][j][k]=(dp[i][j][k]+fun(index+1,j,k+1))%10007;
      }
   }//here
 	
 	int x=pre1[i][s3[k]-'a'];
 	int m;
 	while(x<sz1)
 	{
 		if(k==sz3-1)dp[i][j][k]=(dp[i][j][k]+1)%10007;
 		else dp[i][j][k]=(dp[i][j][k]+fun(x+1,j,k+1))%10007;
 		m=x;
 		x=pre1[m+1][s3[k]-'a'];
 	}
 	
 	
 	 x=pre2[j][s3[k]-'a'];
 	 
 	while(x<sz2)
 	{
 		if(k==sz3-1)dp[i][j][k]=(dp[i][j][k]+1)%10007;
 		else dp[i][j][k]=(dp[i][j][k]+fun(i,x+1,k+1))%10007;
 		m=x;
 		x=pre2[m+1][s3[k]-'a'];
 	}
 	/*for(int index=j;index<sz2;index++){
  	      if(s2[index]==s3[k]){
         if(k==sz3-1) dp[i][j][k]=(dp[i][j][k]+1)%10007;
         else
           dp[i][j][k]=(dp[i][j][k]+fun(i,index+1,k+1))%10007;
      }
   }*/
   
   /*
   for(int ind=0;ind<26;ind++)
   {
   		int x=pre2[j][ind];
   		if(s3[k]==ind && x<sz2)
   		{
   			if(k==sz3-1)dp[i][j][k]=(dp[i][j][k]+1)%10007;
   			else
   				dp[i][j][k]=(dp[i][j][k]+fun(i,x+1,k+1))%10007;
   		}
   }//here
   return dp[i][j][k]%10007;
}
int main(){
   int t;
   scanf("%d",&t);
   while(t--){
      scanf("%s%s%s",s1,s2,s3);
      //cout<<s1<<" "<<s2<<" "<<s3<<endl;
      sz1=strlen(s1);
      sz2=strlen(s2);
      sz3=strlen(s3);
      INIT(dp,-1);
      FOR(i,61)
      	FOR(j,26){	pre1[i][j]=100;pre2[i][j]=100;}
      for(int i=sz1-1;i>=0;i--)
      {
      	for(char c='a';c<='z';c++)
      	{
      		if(s1[i]==c)
      		{
      			pre1[i][c-'a']=i;
      		}
      		else pre1[i][c-'a']=pre1[i+1][c-'a'];
      	}
      }
      for(int i=sz2-1;i>=0;i--)
      {
      	for(char c='a';c<='z';c++)
      	{
      		if(s2[i]==c)
      		{
      			pre2[i][c-'a']=i;
      		}
      		else pre2[i][c-'a']=pre2[i+1][c-'a'];
      	}
      }	
      printf("%d\n",fun(0,0,0)%10007);
      
      
   }
   return 0;
}*/
