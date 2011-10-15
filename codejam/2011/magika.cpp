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
 
char mcomb[512][512];
map<string,int> mopp;
char comb[100][10];
char opp[100][10];
char inp[201];


char lookup[150];
string construct(char a,char b) {
	char temp[100];
	sprintf(temp,"%c%c",a,b);
	return string(temp);
}
string ans;

int main(int argc,char** args)
{

	int t;
	scanf("%d",&t);
 	int kase=1;
 	int c,d,n;
 	char temp[100];
 	while(kase<=t) {
 		scanf("%d",&c);
 		memset(lookup,0,sizeof (lookup));
 		memset(mcomb,0,sizeof (mcomb));
 		ans="";
 		FOR(i,c) {
 			scanf("%s",comb[i]);
 			mcomb[comb[i][0]][comb[i][1]]=comb[i][2];
 			mcomb[comb[i][0]][comb[i][1]]=comb[i][2];
 			
 		}
 		scanf("%d",&d);
 		FOR(i,d) { 
 			scanf("%s",opp[i]); 			
 			lookup[opp[i][0]]=opp[i][1];
 			lookup[opp[i][1]]=opp[i][0];
 		}
		scanf("%d",&n);
		scanf("%s",inp);
		char curr=inp[0];
		string create;
		int p=0;
		int use=1;
		if(n==1) {
			printf("Case #%d: [%c]\n",kase,inp[0]);
			kase++;
			continue;
		}
		char ppp;
		int done=0;
		ans="";
		for(int i=0;i<n;i++) {
			cerr<<"AT START "<<i<<" ans="<<ans<<endl;
			if(ans!="") {

				if((ppp=mcomb[inp[i]][ans[ans.size()-1]])) {
					cerr<<"DOING COMB "<<inp[i]<<ans[ans.size()-1]<<" with "<<ppp<<endl;
					ans[ans.size()-1]=ppp;
				}
				else {
					for(int j=0;j<ans.size();j++) if(lookup[ans[j]]==inp[i]){ans="";break;}
					if(ans!="") ans += inp[i];
				}
			}
			else ans+= inp[i];
			
		}
		
		printf("Case #%d: [",kase);
		kase++;
		if(ans.size()>0)printf("%c",ans[0]);
		for(int i=1;i<ans.size();i++)printf(", %c",ans[i]);
		printf("]\n");		
		 		
 	}
}
