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

double dist(int rr,int cc,int i,int j) {
	double a= (i*i-rr*rr) + j*j-cc*cc;
	return sqrt(a);
}
#define EPS 1e-6
int mat[100][100];
int main(int argc,char** args) { 

	int T,r,c,d;
	string temp;
	scanf("%d",&T);
	FOR(kase,T) {
		cout<<"Case #"<<kase+1<<": ";
		scanf("%d%d%d",&r,&c,&d);
		FOR(i,r) {
			cin>>temp;
			FOR(j,c) {
				mat[i][j]=(temp[j]-'0') + d;
			}
		}
		int rr,cc;
		int ans=0;
		FOR(i,r-2) {
			FOR(j,c-2) {
				rr=i;cc=j;
				for(int k=3;k<=min(c-j,r-i);k++) {
					int m=0;
					double numx=0,numy;
					for(int ii=i;ii<i+k && ii<r;ii++) {
						for(int jj=j;jj<j+k && jj<c;jj++) {
							m+=mat[ii][jj];
							numx+= mat[ii][jj]*ii;
							numy+=mat[ii][jj]*jj;
						}
					}
					
				}
			}
		}
		cout<<ans<<endl;
	}
 	
 	
}
