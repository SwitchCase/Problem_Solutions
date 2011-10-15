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
 
 char inp[200][200]; 
 char out[200][200];
 
 int check(int i,int j) {
 	if(out[i][j]=='#' && out[i+1][j]=='#' && out[i+1][j+1]=='#' && out[i][j+1]=='#')return 1;
 	return 0;
 }
int main(int argc,char** args)
{
	int T;
	int r,c;
	scanf("%d",&T);
	FOR(kase,T) {
		scanf("%d%d",&r,&c);
		cout<<"Case #"<<kase+1<<": \n";
		FOR(i,r) {
			scanf("%s",inp[i]);
		}	
		memcpy(out,inp,sizeof(inp));
		FOR(i,r-1) {
			FOR(j,c-1) {
				if(out[i][j]=='#') {
					if(check(i,j)) {
						out[i][j]='/';
						out[i+1][j]='\\';
						out[i][j+1]='\\';
						out[i+1][j+1]='/';
					}
				}
			}
		}
		bool ans=1;
		
		FOR(i,r) {
			FOR(j,c) {
				if(out[i][j]=='#') {
					ans=0;
					goto next;
				}
			}
		}
		next:
		if(ans) {
			FOR(i,r) {
				cout<<out[i]<<endl;
			}
		}
		else {
			cout<<"Impossible\n";
		}
		
	}
 	
 	
}
