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

#define MAX 10000005
bool prime[MAX];

void doPrimes()
{
    memset(prime,1,MAX);
    prime[0]=prime[1]=0;
    for(int i=4;i<MAX;i+=2)prime[i]=0;
    
    for(int i=3;i*i<=MAX;i+=2) {
        if(prime[i]) {
            for(int j=i*i;j<MAX;j+=2*i)prime[j]=0;
        }
    }
}

void printrest(int n)
{
    if( prime[n-2]) { 
        printf("2 %d",n-2);
        return;
    }
    else {
        for(int i=3;i<n;i+=2) {
            if(prime[i] && prime[n-i]) {
                printf("%d %d",i,n-i);
                return;
            }
        }
    }
}

int main()
{
    int N;
    doPrimes();
    while(scanf("%d",&N)!=EOF)
    {
        if(N<8)printf("Impossible.");
        else if(N%2==0) {
            printf("2 2 ");
            printrest(N-4);
        }
        else {
            printf("2 3 ");
            printrest(N-5);
        }
        printf("\n");
    }
}
