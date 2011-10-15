// <-------------------[sWitCHcAsE]---------------------->

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FORS(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a) for(int i=a;i>=0;i--)
#define pb push_back
#define VI vector<int>
#define VS vector <string>
#define MAX2(a,b) (a)<(b)?(b):(a)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define LEN(s) strlen(s)
#define tests(tc) int tc;scanf("%d",&tc);while(tc--)
#define TEN(n) (long long)pow(10LL,n)
#define foreach(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define bits __builtin_popcount

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

using namespace std;
inline VS split(string s,char* tok){VS vs;char *pch;char *q= (char*)s.c_str();  pch=strtok(q,tok);while(pch !=NULL){vs.pb(string(pch));pch=strtok(NULL,tok);}return vs;}


/*
10 12 10
S 1 9 10
S 2 9 12
S 1 1 1
S 1 1 1
S 1 2 1
S 2 2 1
Q 1
Q 2
Q 9
Q 10
S 10 10 99
Q 10
*/
#define MAX 250010
#define INF 999999999
struct SEG_TREE {
    int s;
    int f;
    ll v;
    SEG_TREE() {
    	s=INF;
    	f=-INF;
    	v=0LL;
	}
};
SEG_TREE Seg_Tree[MAX];

/* Intializes the tree*/
void InitTree(int x, int a,int b) {
    
    if(a>b)return;
    Seg_Tree[x].s=a;Seg_Tree[x].f=b;Seg_Tree[x].v=0;
    if(a==b) {
        return;
    }
    else {
         InitTree(2*x+1, a, (a+b)/2);
         InitTree(2*x+2,(a+b)/2 +1,b);
    }
}

/* Updates the Tree */

void Update(int x, int a, int b, ll v) {
    if(a>b)return;
     if(Seg_Tree[x].s==a && Seg_Tree[x].f==b) {
        Seg_Tree[x].v+=v;
        return;
    }
    if(Seg_Tree[x].s >b || Seg_Tree[x].f<a)return;
    int S,F;
    S=Seg_Tree[x].s;
    F=Seg_Tree[x].f;
    int mid= (S+F)/2;
    if(a>mid) {
        Update(2*x+2,a,b,v);
    }
    else if(b<=mid) {
        Update(2*x +1,a,b,v);
    }
    else {
        Update(2*x + 1,a,mid,v);
        Update(2*x + 2,mid+1,b,v);
    }
}

/*** Queries the tree **/

ll Query(int x, int N) {
    ll res=0LL;
    int S,F;

    while( Seg_Tree[x].s <= N && Seg_Tree[x].f >= N) {
        res+=Seg_Tree[x].v;
        S=Seg_Tree[x].s;
        F=Seg_Tree[x].f;
        if(N>(S+F)/2) {
            x=2*x+2;
        }
        else if(N>=S)x=2*x+1;
        else break;
    }
    
    return res;
}



struct Op {
	int a;
	int b;
	int v;
	char typ;
};

Op quer[MAX];
int scnd_typ[MAX];

int main() {
    int n,m,c;
    char cmd;
    int scnd=0;
    scanf("%d%d%d",&n,&m,&c);
    int u,v,k;
    int qs=0;
    while(m--) {
        scanf(" %c",&cmd);

        if(cmd=='S') {
            scanf("%d%d%d",&u,&v,&k);
			quer[qs].a=u;quer[qs].b=v;quer[qs].v=k;quer[qs].typ=cmd;
			qs++;
			//cerr<<cmd<<endl;
        }
        else if(cmd=='Q') {
            scanf("%d",&u);
            quer[qs].typ=cmd;
            quer[qs].a=u;
            qs++;
            scnd_typ[scnd++]=u;
            //cerr<<cmd<<endl;
        }
    }
    sort(scnd_typ,scnd_typ + scnd);
    scnd= unique(scnd_typ,scnd_typ+scnd)-scnd_typ; /*Count of Unq items*/
    
    InitTree(0,0,scnd+1);
    FOR(i,qs) {
    	if(quer[i].typ =='S') {
    		//cerr<<"PRE S"<<endl;
			u=lower_bound(scnd_typ,scnd_typ + scnd , quer[i].a) - scnd_typ;
			v= upper_bound(scnd_typ,scnd_typ + scnd,quer[i].b) - scnd_typ;
			if(u<v) {    		
				Update(0,u,v-1,quer[i].v);
			}
    	}
    	else {
    		//cerr<<"PRE Q"<<endl;
    		//InOrder(Seg_Tree);
    		int u = lower_bound(scnd_typ,scnd_typ + scnd,quer[i].a) - scnd_typ;
    		ll res=Query(0,u) +c;
    		cout<<res<<endl;
    	}
    }
 
}
