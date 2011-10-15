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

vector<int> P;
#define MAX 32630
void Prime() {
    //P.pb(2);
    int sieve[MAX + 2];
    memset(sieve,1,sizeof sieve);
    sieve[0]=sieve[1]=0;
    for(int i=4;i<=MAX;i+=2)sieve[i]=0;
    for(int i=3;i*i<=MAX;i+=2) {
        if(sieve[i]) {
           // cerr<<"PRIMES "<<i<<endl;
            //P.pb(i);
            for(int j=i*i;j<MAX;j+=2*i) {
                sieve[j]=0;
            }
        }
    } 
    for(int i=0;i<MAX;i++)
      if(sieve[i]) {
          P.pb(i);
          //cerr<<"PRIME :"<<i<<endl;
      }
}
int pp;
int solve(int n,int p) {
    int m,k;
    if(n<=1)return 0;
    m=(P[p]-1 )%n;
    k=solve(n-1,p+1);
    if(k<(n-m-1))return k+m+1;
    else return k-(n-m-1);
}
int main() {
    Prime();
   // cerr<<P.size()<<endl;
    int N;
    int ans[3505];
    FOR(i,3505) {
        ans[i]=solve(i,0)+1;
    }
    while(scanf("%d",&N),N) {
        printf("%d\n",ans[N]);
    }
    //system("pause");
}
