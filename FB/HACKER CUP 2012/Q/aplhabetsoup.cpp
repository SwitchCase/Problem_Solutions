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

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(i,a,n) for(i=a;i<n;i++)
#define ERR(x) cerr<<#x<<" "<<x<<endl
#define pb push_back

using namespace std;

typedef vector<int> VI;
typedef long long ll;
typedef long double ld;

int main(int argc,char** args)
{
	int kases;
	scanf("%d\n",&kases);
	int t=0;
	while(kases--) {
		t++;
		char buff[10000];
		cin.getline(buff,10000);
		int c[26]={0};
		string inp=string(buff);
		FOR(i,inp.size()) {
			if( inp[i]!=' ')c[inp[i]-'A']++;
		}

		int ans = 0;
		string ch="HAKERUP";
		ans = c[2]/2;
		FOR(i,ch.size()) {
			ans=min(ans,c[ch[i]-'A']);
		}
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
}
