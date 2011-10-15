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
 
struct S{
	int h;
	ll v;
}; 


ll stud[4][100005];
int count[4];

S arr[100005];

int main(int argc,char** args)
{
	int N;
	count[0]=count[1]=count[2]=count[3]=count[4]=0;
	scanf("%d",&N);
	int h;
	ll v;
	int ans=0,tans;
	ll vans,vtans;
	for(int i=0;i<N;i++) {
		scanf("%d %lld",&h,&v);
		v--;
		stud[v][count[v]++]=h;
		arr[i].v=v;
		arr[i].h=h;
	}
	for(int i=0;i<4;i++)
		sort(stud[i],stud[i]+count[i]);
		
	for(int i=0;i<count[2];i++) {
		int t=0;
		int curr=stud[2][i];
		t=(upper_bound(stud[0],stud[0]+count[0],curr-1) - lower_bound(stud[0],stud[0]+count[0],curr-1) -1);
		t+=(upper_bound(stud[1],stud[1]+count[1],curr+1) - lower_bound(stud[1],stud[1]+count[1],curr+1)-1);
		
		
	}
	
 	
 	
}
