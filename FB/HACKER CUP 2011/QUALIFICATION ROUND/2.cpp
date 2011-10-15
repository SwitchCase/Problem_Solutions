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
	int i,j,k,N;
	scanf("%d",&N);
	while(N--)
	{
		vector<string> vs;
		int n;
		char buff[100];
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s",buff);
			vs.pb(string(buff));
		}
		sort(vs.begin(),vs.end());
		int arr[10];
		string best="";
		FOR(i,vs.size())
		{
			arr[i]=i;
			best+=vs[i];
		}
		
		do
		{
			string t="";
			FOR(i,vs.size())
			{
				t+=vs[arr[i]];
			}
			if(t<best)best=t;
		}while(next_permutation(arr,arr+vs.size()));
		cout<<best<<endl;
	} 
 	
}
