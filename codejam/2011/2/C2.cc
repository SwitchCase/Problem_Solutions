// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SIZE(t) ((int)((t).size()))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

#define SIEVE_MAX 12345678
#define ISPRIME(n) (!(__sito[(n)>>4] & (1<<(((n)>>1)&7)))) /* only works for odd values */
unsigned char __sito[ (SIEVE_MAX>>4) + 47 ];

int main() {
    memset(__sito,0,sizeof(__sito));
    int __odm = int(3+sqrt(double(SIEVE_MAX)));
    for(int i=3;i<=__odm;i+=2) if(ISPRIME(i)) { 
        int j=i*i; while(j<SIEVE_MAX) { __sito[j>>4] |= 1 << ((j>>1)&7); j+=i<<1; }
    }
    vector<long long> primes(1,2); 
    for (int i=3; i<SIEVE_MAX; i+=2) if (ISPRIME(i)) primes.push_back(i);
    
    int T;
    cin >> T;
    REP(t,T) {
        long long N;
        cin >> N;
        long long spread = 0;
        REP(i,SIZE(primes)) {
            long long p = primes[i];
            if (p*p > N) break;
            long long x=1;
            int pow=0;
            while (x*p <= N) x*=p, ++pow;
            spread += pow-1;
        }
        if (N>1) ++spread;
        printf("Case #%d: %lld\n",t+1,spread);
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
