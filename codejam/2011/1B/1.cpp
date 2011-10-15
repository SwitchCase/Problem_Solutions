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
 
 
char inp[150][150]; 
ld WP[150],OWP[150],OOWP[150];
ld RPI[150];


void print(int N) {
	FOR(i,N) {
		FOR(j,N)
			cerr<<inp[i][j]<<" ";
		cerr<<endl;
	}
}
int main(int argc,char** args)
{
	int T,N;
	scanf("%d",&T);
	FOR(kase,T) {
		scanf("%d",&N);
		FOR(i,N) {
			scanf("%s",inp[i]);

		}
		//print(N);
		int p,w;
		p=0;
		FOR(i,N) {
			p=0;w=0;
			FOR(j,N) {
				if(inp[i][j]!='.') {
					p++;
				}
				if(inp[i][j]=='1') w++;
			}
			WP[i]=1.0*w/p;
		}
		ld temp;
		int it;
		FOR(i,N) {
			temp=0;
			it=0;
			FOR(j,N) {
				if(inp[i][j]!='.') {
					it++;
					w=0;p=0;
					FOR(k,N) {
						if(k==i)continue;
						if(inp[j][k]!='.') p++;
						if(inp[j][k]=='1')w++;	
					}
					temp+=1.0*w/p;
				}
			}
			OWP[i]=temp/it;
		}
		p=0;
		
		FOR(i,N) {
			p=0;temp=0;
			FOR(j,N) {
				if(inp[i][j]!='.')p++, temp+=OWP[j];
				
			}
			OOWP[i]=temp/p;
		}
		FOR(i,N) {
			RPI[i]=.25*WP[i] + 0.5*OWP[i] + .25* OOWP[i];
		}
		cout<<"Case #"<<(kase+1)<<":\n";
		FOR(i,N) {
			printf("%.8LF\n",RPI[i]);
		}
		
	}
 	
 	
}
