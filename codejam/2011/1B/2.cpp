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
 
#define INF 1e15; 
#define EPS 1e-7 

int inp[300][2];
int d,c;

int C,D;
int P[300],V[300];
int imk(ld tim) {
	double mn = -1e15;
	FOR(i, C)
	{
		double tmin = (double)P[i] - tim;
		tmin = max(tmin, mn);
		tmin += ((double)V[i] - 1.) * (double)D;
		double diff = fabs(tmin - (double)P[i]);
		if (diff - tim > EPS)
			return false;
		mn = tmin + D;
	}
	return true;
}
int poss(ld t) {
	//return imk(t);
	cerr<<"------------------------"<<endl;
	cerr<<"TRYING FOR TIME "<<t<<endl;
	ld lastone=-INF;
	lastone= (ld)inp[0][0]-t + (inp[0][1]-1)*d;
	ld ft= fabs((ld)inp[0][0]- lastone);
	if(ft>t && c==1)return 0;
	ld frst;
	ld move;
	int tol,tor;
	ld nl;
	for(int i=1;i<c;i++) {
		cerr<<i<<" : "<<lastone<<" ";
		move=0;
		frst=lastone+d;
		frst=max(frst,inp[i][0]-t);
		nl=frst + (inp[i][1]-1)*d;
		if(frst < (ld)inp[i][0]) {
			
			nl=frst + (inp[i][1]-1)*d;
			cerr<<frst<<" "<<nl<<endl;
			tol=(int)(1.0*inp[i][0] - frst) / (1.0*d) +1;
			if(fabs( inp[i][0]- (frst + tol*d))<1e-8)
				tor=inp[i][1]-tol-1;
			else tor=inp[i][1]-tol;
			if(tor==0) {
				move=fabs(inp[i][0]-frst);
			}
			else {
				move=max( fabs(inp[i][0]-nl) ,fabs(inp[i][0]-frst));
			}
			cerr<<"--------------------------"<<endl;
			if(move>t) {
				cerr<<"FAILED AT "<<i<<" "<<move<<endl;
				cerr<<"--------------------------"<<endl;
				return 0;
			}
			
		}
		else {
		cerr<<"--------------------------"<<endl;
		cerr<<frst<<" "<<nl<<endl;
			move= max(fabs(inp[i][0]-nl),fabs(inp[i][0]-frst));
			if(move>t) {
			cerr<<"FAILED AT "<<i<<" "<<move<<endl;
				cerr<<"--------------------------"<<endl;
				
				return 0;
			}
		}
		lastone=nl;
	}
	cerr<<"--------------------------"<<endl;
	return 1;
}

int main(int argc,char** args)
{
		int T;
		scanf("%d",&T);
		FOR(kase,T) {
			cerr<<"####################################### TEST "<<kase+1<<endl;
			scanf("%d%d",&c,&d);
			C=c;D=d;
			cerr<<c<<" "<<d<<endl;	
			FOR(i,c) {
				
				scanf("%d%d",&inp[i][0],&inp[i][1]);
				cerr<<inp[i][0]<<" "<<inp[i][1]<<endl;
				P[i]=inp[i][0];V[i]=inp[i][1];
			}
			cerr<<"---TEST CASE ENDS "<<endl;
			ld mid;
			ld lo=0,hi=1e7;
			int inl,inh,inm;
			while(fabs(lo-hi)>1e-8) {
				inl=inm=inh=0;
				mid=(lo+hi)/2;
				inl=poss(lo);
				inh=poss(hi);
				inm=poss(mid);
				cerr<<"FOR "<<lo<<" "<<mid<<" "<<hi<<" "<<inl<<" "<<inm<<" "<<inh<<endl;
				if(!inl && !inm) lo=mid;
				else if(inm) hi=mid;
				if(!inl && !inm && !inh)cout<<"U MORON"<<lo<<" "<<mid<<" "<<hi<<endl;
			} 
			mid=(lo+hi)/2;
			printf("Case #%d: %.6Lf\n",kase+1,mid);
			
		}
 	
}
