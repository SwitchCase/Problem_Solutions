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

#define SHIFT 25
 
int inp[30][30];
int mat[27][27][1301]; 
int main(int argc,char** args)
{
	int T;scanf("%d",&T);
	int m,n;
	int A,B,curr;
	int mm=0;
	while(T--) {
		scanf("%d %d",&m,&n);
		scanf("%d %d",&A,&B);
		A+= (SHIFT*m);
		B+=(SHIFT*m);
		mm=0;
		FOR(i,m) {
			FOR(j,n) {
				scanf("%d",&inp[i][j]);
				inp[i][j]+=SHIFT;
				mm=max(mm,inp[i][j]);
			}
		}
		//cout<<"ADJUSTED A AND B "<<A<<" "<<B<<endl;
		//system("pause");
		mm=mm*m;
		memset(mat,0,sizeof mat);
		FOR(i,n) {
			mat[m-1][i][inp[m-1][i]]=1;
		}
		for(int i=m-2;i>=0;i--) {
			for(int j=0;j<n;j++) {
				curr=inp[i][j];
				for(int k=0;k<=1300;k++) {
					if(j-1>=0 && k>=curr && mat[i+1][j-1][k-curr]==1)mat[i][j][k]=1;
					else if(j+1<n && k>=curr && mat[i+1][j+1][k-curr]==1)mat[i][j][k]=1;
					else if(k>=curr && mat[i+1][j][k-curr]==1)mat[i][j][k]=1;
				} 
			}
		}
		int ansmin=10000000,ansmax=-1;
		FOR(i,n) {
			for(int k=max(A,0);k<=B;k++) {
				//if(mat[0][i][k])cout<<k-m*SHIFT<<" EXISTS in"<<i<<endl;
				if( mat[0][i][k] ) {
					ansmax=max(ansmax,k);
					ansmin=min(ansmin,k);
				}
			}	
		}
		if(ansmin == 10000000) {
			if(ansmax !=-1) {
				ansmax-=m*SHIFT;
				cout<<"NO "<<ansmax<<endl;
			}
			else cout<<"NO NO"<<endl;
		}
		else {
			ansmin-=m*SHIFT;
			if(ansmax!=-1) {
				ansmax-= m*SHIFT;
				
				cout<<ansmin<<" "<<ansmax<<endl;		
			}
			else {
				cout<< ansmin<<" NO"<<endl;
			}
		}
		
	}
 	
 	
}
