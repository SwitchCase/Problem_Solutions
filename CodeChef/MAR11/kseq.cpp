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
#define FORS(i,a,n) for(int i=a;i<n;i++)
#define ERR(x) cerr<<#x<<" "<<x<<endl
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
typedef long double ld;

struct II {
	int val;
	int f;
	int rank;
};
 
map<int,int> freq;
vector<vector<int> > ans;
vector<vector<int> > TEMP;
II nums[50005];

int CMP(II a,II b) {
	if(a.f==b.f) {
		return a.rank < b.rank;
	}
	else return a.f > b.f;
}

int main(int argc,char** args)
{
	int T;
	scanf("%d",&T);
	while(T--) {
		int N,K;
		scanf("%d %d",&N,&K);
		freq.clear();
		ans.clear();
		TEMP.clear();
		int M=N/K;
		FOR(i,M+1) {
			ans.pb(vector<int>());
			TEMP.pb(vector<int>());
		}
		int v,t;
		int maxfreq=0;
		FOR(i,N) {
			scanf("%d",&v);
			ERR(v);
			t=(freq[v]++);
			t++;
			if(maxfreq<t)maxfreq=t;
		}
		ERR(maxfreq);
		if(maxfreq>M) {
			printf("-1\n");
			continue;
		}
		map<int,int>::iterator it=freq.begin();
		int count=0;
		for(;it!=freq.end();it++) {
			nums[count].value=(*it).first;
			nums[count].f=(*it).second;
			nums[count].rank=++count;
			//TEMP[(*it).second].pb((*it).first);
		}	
		sort(nums,nums+count,CMP);
	
		for(int i=0;i<count;i++) {
			int times=nums[i].second;
			int curr=nums[i].first;
			for(int j=0,m=1;j<times;m++) {
				if(ans[m].size()<M) {
					j++;
					ans[m].pb(curr);
				}
				else continue;
			}
		}
		
		for(int i=1;i<=M;i++)sort(ans[i].begin(),ans[i].end());
		for(int i=1;i<=M;i++) {
			//ERR(ans[i].size());
			for(int j=0;j<ans[i].size();j++) {
				if(i==M && j==(ans[i].size()-1)) {
					printf("%d\n",ans[i][j]);
				}
				else printf("%d ",ans[i][j]);
			}
		}
	}
}
