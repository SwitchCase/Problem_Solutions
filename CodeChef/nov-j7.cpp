
// <-------------------[sWitCHcAsE]---------------------->

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>

#define FOR(i,a) for(int i=0;i<a;i++)
#define FORS(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a) for(int i=a;i>=0;i--)
#define foreach(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define MAX2(a,b) (a)<(b)?(b):(a)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define LEN(s) strlen(s)
#define tests(tc) int tc;scanf("%d",&tc);while(tc--)
#define TEN(n) (long long)pow(10LL,n)
#define bits __builtin_popcount
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

using namespace std;
inline VS split(string s,char* tok){VS vs;char *pch;char *q= (char*)s.c_str();	pch=strtok(q," ");	while(pch !=NULL){vs.pb(string(pch));pch=strtok(NULL,tok);}return vs;}
inline int digitsIn(ll n){int ans=0;while(n){n/=10;ans++;}return ans;}


int main()
{
	int s,p;
	tests(tc)
	{
		scanf("%d%d",&p,&s);
		ld vol=0;
		
		ld low=0.0;
		ld high=(ld)p/4.0 - 2.0;
		ld mid;
		ld bplusc;
		ld f=(ld)s/2.0;
		ld bc;
		ld tvol;
		/*bplusc=(ld)p/8.0;
		ld a=bplusc;
		bc=f-a*bplusc;
		tvol=a*bc;
		cout<<a<<" "<<bc<<endl;
		cout<<"---------["<<tvol<<" ]------------"<<endl;
		while(1)
		{
			if(fabs(high-low)<=1e-9)break;
			mid=(low+high)/2.0;
			bplusc=((ld)p/4.0) - (ld)mid;
			bc=f-mid*(bplusc);
			tvol=mid*bc;
			if(tvol>vol)
			{
				cerr<<"GRTR for a= "<<mid<<endl;
				cerr<<bplusc<<"  "<<bc<<"  "<<vol<<"  "<<tvol<<endl;
				vol=tvol;
				low=mid;
			}
			else
			{
				high=mid;
			}
			
		}*/
		
		ld a1,a2;
		ld delta;
		delta= sqrt((ld)p*p - 24*(ld)s);
		a1=(ld)p-delta;
		a2=(ld)p + delta;
		a1/=12.0;
		a2/=12.0;
		//cout<<"DELTA "<<delta<<" "<<"a1 "<<a1<<" a2 "<<a2<<endl;
		ld x1=(p-8*a1)/4.0;
		ld x2=(p-8*a2)/4.0;
		vol=x1*a1*a1;
		ld vol2=x2*a2*a2;
		if(vol<vol2)vol=vol2;
		printf("%.2Lf\n",vol);
	}
}
