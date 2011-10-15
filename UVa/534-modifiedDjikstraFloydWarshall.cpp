
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
typedef pair<int,double> id;
typedef vector<id> vid;
typedef vector<vid> vvid;


/*
	Ideally.. a modified form of Djikstra shud have sufficed but we used a Floyd Warshall because of the presence
	 of double. Remmeber that two pair<,>s are equal only if both members of each pait satisfy the condition "=".
*/
double Graph[201][201];
char buff[1024];
typedef pair<double,double> dd;
dd arr[201];
int n;

double dist(int a,int b)
{
	double p=arr[a].first - arr[b].first;
	double q=arr[a].second - arr[b].second;
	return sqrt(p*p + q*q);
}

double d[201];



int main()
{
	int kase=1;
	double x,y;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)break;
		FOR(i,n)
		{
			scanf("%lf%lf",&x,&y);
			arr[i]=dd(x,y);
			
		}
		swap<dd>(arr[1],arr[n-1]);
		double ds;
		FOR(i,n)
		{
			FORS(j,i+1,n)
			{
				ds=dist(i,j);
				Graph[i][j]=ds;
				Graph[j][i]=ds;
				
			}
		}
		FOR(k,n)
		{
			FOR(i,n)
			{
				FOR(j,n)
				{
					Graph[i][j]=min(Graph[i][j],max(Graph[i][k],Graph[k][j]));
				}
			}
		}
		
		cout<<"Scenario #"<<(kase++)<<endl;
		printf("Frog Distance = %.3lf\n\n",Graph[0][n-1]);
		
	}
}
