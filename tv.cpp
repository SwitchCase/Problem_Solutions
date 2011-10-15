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
	int i,j;
	freopen("tc.txt","w",stdout);
	cout<<"{ ";
	FOR(i,50)
	{
		cout<<"\"";
		FOR(j,50)
		{
			cout<<(rand()%3==0?"W":"B");
		}
		cout<<"\"";
	}

 	
}
