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


struct Node {
    int s;
    int f;
    ll v;
    Node * left;
    Node *right;
    Node() {
        s=-1;
        f=-1;
        v=-1;
        left=NULL;
        right=NULL;
    }
    Node(int S, int F,ll V=0LL) {
        s=S;
        f=F;
        v=V;
        left=NULL;
        right=NULL;
    }
};

Node* Seg_Tree;

/* Intializes the tree*/
void InitTree(Node ** root,int a,int b,ll v) {
    
    if(*root==NULL) {
        *root=new Node(a,b,v);
    }
    if(a==b)return;
    else {
        InitTree(&(*root)->left, a, (a+b)/2,0);
        InitTree(&(*root)->right,(a+b)/2 +1,b,0);
    }
    
}

/* Updates the Tree */

void Update(Node *root, int a, int b, ll v) {
    if(root==NULL)return;
    if(root->s==a && root->f==b) {
        root->v+=v;
        return;
    }
    int S,F;
    S=root->s;
    F=root->f;
    int mid= (S+F)/2;
    if(a>mid) {
        Update(root->right,a,b,v);
    }
    else if(b<=mid) {
        Update(root->left,a,b,v);
    }
    else {
        Update(root->left,a,mid,v);
        Update(root->right,mid+1,b,v);
    }
}

/*** Queries the tree **/

ll Query(Node *root, int N) {
    ll res=0LL;
    if(root==NULL) return 0LL;
    int S,F;
    S=root->s;
    F=root->f;
    int mid=(S+F)/2;
    res+=root->v;
    if(N>mid) res+= Query(root->right,N);
    else res+=Query(root->left,N);
    return res;
}

void InOrder(Node * root) {
    if(root!=NULL) {
        InOrder(root->left);
        printf(" (%d %d %d), ",root->s,root->f,root->v);
        InOrder(root->right);
    }
}

struct Op {
	int a;
	int b;
	int v;
	char typ;
};

Op quer[250005];
int scnd_typ[250005];

int main() {
    Seg_Tree=NULL;
    int n,m,c;
    char cmd;
    int scnd=0;
    scanf("%d%d%d",&n,&m,&c);
    InitTree(&Seg_Tree,1,n,c);
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
    FOR(i,qs) {
    	if(quer[i].typ =='S') {
    		//cerr<<"PRE S"<<endl;
			u=lower_bound(scnd_typ,scnd_typ + scnd , quer[i].a) - scnd_typ;
			v= upper_bound(scnd_typ,scnd_typ + scnd,quer[i].b) - scnd_typ;
			if(u<v) {    		
				u=scnd_typ[u];
				v=scnd_typ[v-1];
				Update(Seg_Tree,u,v,quer[i].v);
			}
    	}
    	else {
    		//cerr<<"PRE Q"<<endl;
    		//InOrder(Seg_Tree);
    		ll res=Query(Seg_Tree,quer[i].a);
    		cout<<res<<endl;
    	}
    }
    //system("pause");
}

