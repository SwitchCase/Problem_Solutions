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

bool isSQ(int k)
{
    int r=sqrt(k);
    if( r*r ==k)return true;
    return false;
}
int main()
{
    int ans[51]={0};
    vector<int> pegs[52];
    int st=1;
    int currm=1;
    while(currm<=50) {
        int added=0;
        for(int i=0;i<currm;i++) {
            if(pegs[i].size()==0) {
                pegs[i].pb(st);
                added=1;
                break;
            }
            else {
                if(isSQ(pegs[i][pegs[i].size()-1] + st)) {
                    pegs[i].pb(st);
                    added=1;
                    break;
                }
            }
        }
        if(!added) {
            ans[currm]=st-1;
            pegs[currm].pb(st);
            currm++;    
            
        }
        st++;
    }
    int T,N;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        printf("%d\n",ans[N]);
    }
}
