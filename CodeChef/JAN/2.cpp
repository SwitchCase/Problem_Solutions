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
 
int main(int argc,char** args)
{
	int i;
  string a2="ADOPQR";
  string a3="B";
  string q;
  int n;scanf("%d",&n);
  while(n--)
  {
  	int ans=0;
  	cin>>q;
  	FOR(i,q.size())
  	{
  		if(q[i]=='B')ans+=2;
  		else if(a2.find(q[i],0)!=string::npos)ans++;
  	}
  	cout<<ans<<endl;
  }
 	
 	
}
