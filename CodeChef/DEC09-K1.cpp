
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
#define INIT(arr,val) memset(arr,val,sizeof arr)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

using namespace std;
inline VS split(string s,char* tok){VS vs;char *pch;char *q= (char*)s.c_str();	pch=strtok(q," ");	while(pch !=NULL){vs.pb(string(pch));pch=strtok(NULL,tok);}return vs;}
inline int digitsIn(ll n){int ans=0;while(n){n/=10;ans++;}return ans;}
typedef pair<int,int> ii;
int N;
int a,b,c;
ii points[2001];

bool cmpy(ii a,ii b)
{
	return a.second<b.second;
}
bool cmpx(ii a,ii b)
{
	return a.first<b.first;
}
ld dist(ld x1,ld x2,ld y1,ld y2)
{
	return (ld)sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}


ld Round(ld a)
{
	ld d=1e7;
	return (a*d+.5)/d;
}
int main()
{
	int tx,ty;
	ld ans=0;
	tests(tc)
	{
		ans=0;
		scanf("%d",&N);
		scanf("%d%d%d",&a,&b,&c);
		FOR(i,N)
		{
		
			scanf("%d%d",&tx,&ty);
			points[i]=make_pair(tx,ty);
		}
		if(a==0)
		{
		
			ld x=points[0].first;
			ld y=-1.0*c/b;
		
			ld low=-5000.0;
			ld high=5000.0;
			ld mid;
			ld temp=1e10;
			ld temp1;
			ld dl;
			ld dh;
			do
			{
				dl=0;
				x=low;
				y=-1.0*(c+a*x)/b;
				FOR(i,N)
				{
					dl+=dist(x,points[i].first,y,points[i].second);			
				}
				dh=0;
				x=high;
				y=-1.0*(c+a*x)/b;
				FOR(i,N)
				{
					dh+=dist(x,points[i].first,y,points[i].second);			
				}
				if(dl<dh)high=(high+low)/2;
				else low=(high+low)/2;
				
			}while(fabs(dl-dh)>1e-8 || fabs(high-low)>1e-12);
			//cout<<"BRUTE "<<temp<<endl;
			printf("%.6Lf\n",Round(dh));
		}
		else 
		{
			ld x=(ld)-1.0*c/a;
			ld y=points[0].second;
			//cerr<<"BRUTING\n";
			ld low=-5000.0;
			ld high=5000.0;
			ld mid;
			ld temp=1e10;
			ld temp1;
			ld dl;
			ld dh;
			do
			{
				dl=0;
				y=low;
				x=-1.0*(c+b*y)/a;
				FOR(i,N)
				{
					dl+=dist(x,points[i].first,y,points[i].second);			
				}
				dh=0;
				y=high;
				x=-1.0*(c+b*y)/a;
				FOR(i,N)
				{
					dh+=dist(x,points[i].first,y,points[i].second);			
				}
				if(dl<dh)high=(high+low)/2;
				else low=(high+low)/2;
				
			}while(fabs(dl-dh)>1e-8 || fabs(high-low)>1e-12);
			//cout<<"BRUTE "<<temp<<endl;
			printf("%.6Lf\n",Round(dh));
		}
		
	}
}
