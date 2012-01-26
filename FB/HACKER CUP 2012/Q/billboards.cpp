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
#define READN(a) scanf("%d", &a);
using namespace std;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long ll;
typedef long double ld;
 
inline VS split(string s,char* tok){VS vs;char *pch;char *q= (char*)s.c_str();	pch=strtok(q,tok);while(pch !=NULL){vs.pb(string(pch));pch=strtok(NULL,tok);}return vs;}

int fits(int W, int H, VS words, int font)
{
	int ind = 0;
	int n = words.size();
	int rows = H/font;
	int cols = W/font;
	int cr = 0, cc = 0;
	cerr<<" --- "<<words.size()<<endl;
	while(cr<rows && ind<n) {
		cerr<<"On row "<<cr<<" and col "<<cc<<" for word "<<words[ind]<<" ";
		int cws = words[ind].size();
		if ( cws <= cols-cc) {
			cerr<<" FIT ";
			cc+=cws;
			ind++;
			if ( cc+1 < cols)cc++;
		}
		else {
			cc = 0;
			cr++;
			cerr<<" going to next row ";
		}
		cerr<<endl;
	}
	if ( ind < n) cerr<<"The word i could not fit was of size "<<words[ind].size()<<" in fnt "<<font<<endl;
	if ( ind < n)return 0;
	return 1;
}

int doBrute(int W, int H, VS words)
{
	int larger = max(W,H);
	int ans = 0;
	FORS(i,1,larger+1) {
		if ( fits(W, H, words, i)) ans = i;
	}
	return ans;
}

int doBinarySearch(int W, int H, VS words)
{
	int lo = 1,hi=max(W,H);
	while(lo<hi) {
		
		int mid = (lo+hi)/2;
		if ( mid==lo)break;
		cerr<<"trying "<<mid<<" hi "<<hi<<" lo "<<lo<<endl;
		int v = fits(W,H,words,mid);
		if (v)lo=mid;
		else hi=mid-1;
	}
	if ( fits(W,H,words,hi))return hi;
	else return lo;
}

int main(int argc,char** args)
{
	int kase;
	READN(kase);
	int tk = 0;
	while(kase--) {
		tk++;
		int W,H;
		string inp;
		char buff[10000];
		scanf("%d %d %[a-zA-Z0-9 ]s",&W, &H, buff);
		//printf(" Read %s\n",buff);
		inp = string(buff);
		VS words = split(inp, " ");
		int ans = doBrute(W,H,words);
		int bans = doBinarySearch(W,H,words);
		printf("Case #%d: %d\n",tk, ans);
		cout<<"ans is "<<bans<<endl;
	}

}
