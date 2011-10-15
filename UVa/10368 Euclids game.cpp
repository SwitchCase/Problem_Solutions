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

#define P 1
#define N 0

int solve(ull K, ull M) {
    if(K<M)return solve(M,K);
    if(K%M==0)return P;
    else if(K%M==1 && K<2*M) return N;
    else if(K%M==1 && K>2*M)return P;
    else {
        ull b=K%M;
        int ans=solve(M,b); // remove the maximum possible.
        if(ans==N)return P;
        else if(K>=2*M)return P;
        else return N;
    }
}
int main() {
    ull a,b;
    while(1) {
        cin>>a>>b;
        if(a==b && a==0)break;
        int ans=solve(a,b);
        if(ans)
            cout<<"Stan wins"<<endl;
        else cout<<"Ollie wins"<<endl;
    }
}
