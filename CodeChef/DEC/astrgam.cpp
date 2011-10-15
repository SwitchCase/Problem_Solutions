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
typedef pair<string,string> ss;
map<string,int> use; 
map<string,int> dp;
//#define DEBUG

int mG;
int alwd[901];

inline VI findall(string a, string s)
{
	VI ans;
	int p;
	while((p=a.find(s))!=string::npos)
	{
		ans.pb(p);
		a=a.substr(p+s.size());
	}
	return ans;
}
int main_t()
{
	int T;scanf("%d",&T);
	string s1,s2;
	while(T--)
	{
		cin>>s1>>s2;
		VI ans=findall(s1,s2);
		cout<<"ANS FOR "<<s1<<" "<<s2<<" ";
		for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
		cout<<endl;
	}
}
void doGrundy(string t)
{
	map<string,int>::iterator it;
	memset(alwd,0,sizeof alwd);
	//FOR(i,mG+2)alwd.insert(i);
	int g=0,cg=-1;
	#ifdef DEBUG
	cout<<"*******************\nDOING :"<<t<<":"<<endl;
	#endif
	for(it=use.begin();it!=use.end();it++)
	{
		if(t== (*it).first)
		{
			cg=0;
			alwd[0]=1;
		}
		else 
		{
			
			VI poss=findall(t,(*it).first);
			#ifdef DEBUG
			cout<<"NO OF MATCHES FOUND "<<poss.size()<<endl;
			#endif
			for(int i=0;i<poss.size();i++)
			{
				cg=0;
				int p=poss[i];
			
				string t1=t.substr(0,p);
				#ifdef DEBUG
				cout<<"REMOVED "<<(*it).first<<" at"<<p<<" "<<t1<<" ::"<<endl;
				#endif
				assert(dp.find(t1)!=dp.end());
				cg=dp[t1];
					
				if(p+ ((*it).first).size() !=t.size())
				{
					t1=t.substr(p+ ((*it).first).size());
					#ifdef DEBUG
					cout<<" contd. and "<<t1<<" ::";
					#endif
					assert(dp.find(t1)!=dp.end());
					cg=cg^dp[t1];
				}
				#ifdef DEBUG
				cout<<endl;	
				#endif
				alwd[cg]=1;
			}
		}
		//if(g==cg)g++;
		//alwd[cg]=1;
	}
	int i;
	//sort(alwd.begin(),alwd.end());
	FOR(i,901)
	{
		if(alwd[i]==0)
		{
			g=i;break;alwd[cg]=1;
		}
	}
	dp[t]=g;
	if(g>mG)mG=g;
	#ifdef DEBUG
	cout<<"GRUNDY OF "<<t<<" "<<g<<endl;
	cout<<"*********************\n"<<endl;
	#endif
}

/*
void generate(string a, vector<string> &poss)
{
	map<string,int>::iterator it;
	for(it=use.begin();it!=use.end();it++)
	{
		
	}
}*/

int main()
{
	int i,j,k,cc,cd,cu;
	int T;scanf("%d",&T);
	map<string,int> unq;
	string inp,temp,dic[35];
	int n;
	
  	while(T--)
  	{
  		unq.clear();
  		use.clear();
  		dp.clear();
  		dp[""]=0;
  		cin>>inp;
  		n=inp.size();
  		scanf("%d",&cc);
  		cd=0;
  		FOR(i,cc)
  		{
  			cin>>temp;
  			if(unq.find(temp)!=unq.end())continue;
  			dic[cd++]=temp;
  		}
  		cu=0;
  		FOR(i,cd)
  		{
  			if(inp.find(dic[i])!=string::npos)
  			{
  				use[dic[i]]=1;
  			}
  		}
  		
  		#ifdef DEBUG
  		cout<<"***********DICTIONARY***********"<<endl;
  		for(map<string,int>::iterator it=use.begin();it!=use.end();it++)
  		{
  			cout<<(*it).first<<endl;;
  		}
  		cout<<"************ENDS**************"<<endl;
  		#endif
  		
 		for(int L=1;L<=n;L++)
 		{
 			for(int j=0;j<=n-L;j++)
 			{
 				temp=inp.substr(j,L);
 				doGrundy(temp);
 			}
 		}
 		if(dp.find(inp)!=dp.end())
 		{
 			if(dp[inp]==0)cout<<"Tracy"<<endl;
 			else cout<<"Teddy"<<endl;
 			continue;
 		}
 		else cout<<"Tracy"<<endl;
 		
 	 	
  	}
	
 	
 	
}
