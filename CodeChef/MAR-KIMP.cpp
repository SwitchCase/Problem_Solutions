
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
#include <cassert>

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

//string pre[152][302][2];
char inp[152][302];
int n,l,k;
int mat[152][152];
//string stm[152][152];
int dp[152][502];
//string sols[152][502];
ii paths[152][502];

/*
void preprocess()
{
	FOR(i,n)
	{
		pre[i][0][0]=inp[i][0];
		pre[i][0][1]=inp[i][l-1];
		FORS(j,1,l-1)
		{
			pre[i][j][0]=pre[i][j-1][0]+inp[i][j];
			string y="";
			
			pre[i][j][1]=(y+inp[i][l-j-1])+pre[i][j-1][1];
		//	cerr<<i<<" : "<<"PRE "<<pre[i][j][0]<<"  SUFF "<<pre[i][j][1]<<endl;
		}
	}
}
int len(int suf,int pref)
{
	//cerr<<"LEN "<<suf<<" "<<pref<<endl;
	FORR(i,l-2)
	{
		int t=pre[suf][i][1].compare(pre[pref][i][0]);
		//cout<<"COMPARING "<<pre[suf][i][1]<<"  "<<pre[pref][i][0]<<"  =  "<<t<<endl;
		
		if(t==0){ return i+1; }
	}
	return 0;
}
void construct()
{
	int t;
	FOR(i,n)
	{
		t=len(i,i);
		t=mat[i][i]=l - t;
		
		stm[i][i]= inp[i].substr(l-t, t);
		//cerr<<" t = "<<t<<" \""<<stm[i][i]<<"\""<<endl;
	}
	FOR(i,n)
	{	
		FOR(j,n)
		{
			if(i==j)continue;
			t=len(i,j);
			t=mat[i][j]=l - t;
			stm[i][j]=inp[j].substr(l-t,t);
			//cerr<<" t = "<<t<<" \""<<stm[i][i]<<"\""<<endl;
		}
		
	}
}*/
void preprocess2()
{
	INIT(tmat,0);
	FOR(i,n)
	{
		FOR(j,n)
		{
			FORS(k,1,l)
			{
				if(inp[i][k]!=inp[j][tmat[i][j]])tmat[i][j]=0;
				if(inp[i][k]==inp[j][tmat[i][j]])tmat[i][j]++;
			}
			tmat[i][j]=l-tmat[i][j];
		}
	}
	FOR(i,n)
	FOR(j,n)mat[i][j]=tmat[j][i];
	
}


int main()
{
	tests(tc)
	{
		scanf("%d%d%d",&n,&l,&k);
		FOR(i,n)
		{
			scanf("%s",inp[i]);
		}
		//preprocess();
		//construct();
		preprocess2();
		INIT(dp,0);
		
		FOR(i,n)
		{
			dp[i][0]=l;
		//	sols[i][0]=inp[i];
			paths[i][0].first=i;
			paths[i][0].second=0;
		}
		
		cout<<"----------mat---------"<<endl;
		FOR(i,n)
		{
			FOR(j,n)
			cout<<""<<mat[i][j]<<" ";
			cout<<endl;
		}
		cout<<"----------mat---------"<<endl;
		int K=k;
		FORS(k,1,K)

		{
			FOR(s,n)
			{
				dp[s][k]=987654321;
				//sols[s][k]="";
				FOR(f,n)
				{
					if(dp[s][k]> dp[f][k-1] + mat[s][f])
					{
						dp[s][k]=dp[f][k-1] + mat[s][f];
					//	sols[s][k]= sols[s][k-1] + stm[s][f];
						paths[s][k]=ii(f,mat[s][f] + dp[f][k-1] - l);
					}
				}
				
			}
		}
		/*
		cerr<<"----------sols----------"<<endl;
		FOR(i,n)
		{
			FOR(j,K)
			cerr<<"\""<<sols[i][j]<<"\" ";
			cerr<<endl;
		}
		cerr<<"----------sols----------"<<endl;*/
		int ans=987654321;
		int ians=-1;
		FOR(i,n)if(dp[i][K-1]<ans){ans=dp[i][K-1];ians=i;}
		cout<<ans<<endl;
		//cout<<sols[ians][K-1]<<endl;
		ans=ians;
		printf("%s",inp[paths[ians][0].first]);
		int prev=ians;
		FORS(i,1,K)
		{
			prev=ians;
			ians=paths[prev][i].first;
			printf("%s",inp[ians] + l - mat[prev][ians]);
		}
		printf("\n");
		ians=ans;
		int t=0;
		cout<<paths[ians][0].first<<" 0"<<endl;
		FORS(i,1,K)
		{
			prev=ians;
			ians=paths[ians][i].first;
			t+=mat[prev][ians];
			cout<<ians<<" "<<t<<endl;
			
		//	cerr<<"prev "<<prev<<" ans "<<ians<<endl;
			
			
		}
		cout<<endl;
		
	}
}
