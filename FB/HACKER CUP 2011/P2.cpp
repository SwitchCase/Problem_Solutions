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

#define MOD 10000000007ll; 
map<string,ll> dp;

ll rec(string t)
{
	//cerr<<"CALLED "<<t<<endl;
	if(dp.find(t)==dp.end())
	{
		ll ans=1;
		int aa=0,bb=0;
		int sz=t.size();
		string ty;
		for(int l=2;l<=sz;l++)
		{
			for(int i=0;i< sz-l+1;i++)
			{
				string temp=t.substr(i,l);
				//cerr<<"Substr "<<temp<<endl;
				aa=bb=0;
				for(int k=0;k<temp.size();k++)
				{
					if(temp[k]=='a')aa++;
					if(temp[k]=='b')bb++;
					if(aa>0 && bb>0)break;
				}
				if(aa>0 && bb>0)
				{
					//cerr<<"DOING 1"<<endl;
					ty= t.substr(0,i)+ "a" + t.substr(i+l,sz);
					ans+= rec(ty) %MOD;
					ty=t.substr(0,i)+ "b" + t.substr(i+l,sz);
					ans+= rec(ty)%MOD;
				}
				else if(bb>0)
				{
					ty= t.substr(0,i)+ "b" + t.substr(i+l,sz);
					//cerr<<"DOING 2"<<endl;
					ans+= rec(ty)%MOD;
				}
				
				else
				{
					//cerr<<"DOING 3"<<endl;
					ty= t.substr(0,i)+ "a" + t.substr(i+l,sz);
					 ans+= rec(ty)%MOD;
					 
				}
			}
		}
		return dp[t]=ans%MOD;
	}
	else return dp[t];
}
int main(int argc,char** args)
{
	int i,j,k;
	int N;
	char inp[100];
	scanf("%d",&N);

	dp.clear();
		dp["aa"]=2;
		dp["ab"]=dp["ba"]=3;
		dp["bb"]=2;
	while(N--)
	{
		scanf("%s",inp);
		
		string t=string(inp);
		int sz=strlen(inp);
		cerr<<"SZIE "<<sz<<endl;
		ll ans=rec(t);
		cout<<ans<<endl;
	}
 	
 	
}
