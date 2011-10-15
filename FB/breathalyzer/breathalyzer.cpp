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
 
vector<string> dict[18];

//#define DEBUG

int leven(char* inp,string m)
{
	int i,j;
	int dp[strlen(inp)+4][m.size()+4];	
	int n=strlen(inp);
	int mm=m.size();
	FOR(i,n+1)
		dp[i][0]=i;
		
	FOR(i,mm+1)
		dp[0][i]=i;
		
	for(j=1;j<=mm;j++)
	{
		for(i=1;i<=n;i++)
		{
			if(inp[i-1]==m[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
			{	
				dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
			}
		}
	}
	#ifdef DEBUG
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=mm;j++)cerr<<dp[i][j]<<" ";
			cerr<<endl;
		}
	#endif
	return dp[n][mm];
}

int main_T()
{
	int T;scanf("%d",&T);
	string s1,s2;
	while(T--)
	{
		cin>>s1>>s2;
		cout<<leven((char*)s1.c_str(),s2)<<endl;
	}
}


//#define DEBUG


int BRUTE(char * inp)
{
	int i,j,k;
	int curr=1000000000;
	FOR(i,18)
	{
		FOR(j,dict[i].size())
		{
			curr=min(curr,leven(inp,dict[i][j]));
		}
	}
	return curr;
}

void toupper(char *inp)
{
	int i;
	int n=strlen(inp);
	FOR(i,n)
	{
		if(inp[i]>'Z')
		{
			inp[i]= (inp[i]-'a')+'A';
		}
	}
}

int main(int argc,char** args)
{
	int i,j,k;
	int nd=0;
	string dictionary;
	string temp;
	char inp[10000];
	#ifdef DEBUG
		dictionary="twl06.txt";
	#else 
		dictionary="/var/tmp/twl06.txt";
	#endif
	
	freopen(dictionary.c_str(),"r",stdin);
	int m=0;
	int arr[20]={0};
	while((cin>>temp))
	{
		dict[temp.size()].pb(temp);
		m=max(m,(int)temp.size());
	}
	
	#ifdef DEBUG
		cout<<m<<endl;
		FOR(i,18)
		{
		
			cout<<i<<" = "<<dict[i].size()<<endl;
		}
	#endif
	freopen(args[1],"r",stdin);
	int score=0;
	int len,l;
	int curr,fin;
	int currl;
	int iter=1;
	int BRUTED=0;
	
	while(scanf("%s",inp)!=EOF)
	{
		
		toupper(inp);
		
		#ifdef DEBUG
			cout<<"INPUT "<<inp<<endl;
		#endif
		
		l=len=strlen(inp);
		#ifdef DEBUG
			BRUTED+=BRUTE(inp);
		#endif
		curr=len;
		if(len>15)len=15;
		FOR(i,dict[len].size())
		{
			curr=min(curr,leven(inp,dict[len][i]));
			if(curr==0)break;
		}
		#ifdef DEBUG
					cerr<<"FOR : "<<inp<<" DID default "<<curr<<endl;
		#endif
		fin=curr;
		iter=1;
		currl=len;
		while( iter < curr  )
		{
		
			for(j=-1;j<=1;j++)
			{
				
				#ifdef DEBUG
					cerr<<"DOING "<<(len+iter*j);
				#endif
				currl=len+iter*j;
				if(j==0)continue;
				if(currl<0 || currl > 15)continue;
				FOR(i,dict[currl].size())
				{
					curr=min(curr,leven(inp,dict[currl][i]));
					if(curr==0)break;
				}
				#ifdef DEBUG
					cerr<<" and found "<<curr<<" as best."<<endl;
				#endif
			}
			iter++;
		}
		
		
		
		/*for(i=len-curr+1;i!=len && i<=len+curr-1 && i>=0 ;i++)
		{
			FOR(j,dict[i].size())
			{
				
				fin=min(fin,leven(inp,dict[i][j]));
			}
		}*/
		
		
		score+=curr;
	}
	#ifdef DEBUG
		cout<<"BRUTE "<<BRUTED<<endl<<" ANS :";
	#endif
	cout<<score<<endl;
	
}
