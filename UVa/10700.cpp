
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
#define INF 1LL<<62;
ll dpmax[13][13];
ll dpmin[13][13];
int oper[13];
int operand[13];
int n;
int op=0;
int opa=0;

ll operation(ll val1,ll val2, int ind)
{
	if(oper[ind]=='*')return val1 * val2;
	else if(oper[ind]=='+')return val1+val2;
	else return val1;
}

int main()
{
	string s;
	tests(tc)
	{
		cin>>s;
		INIT(dpmax,0);
		INIT(dpmin,0);
		INIT(oper,-1);
		INIT(operand,-1);
		string t="";
		op=0;opa=0;
		FOR(i,s.size())
		{
		
			if(s[i]=='*' || s[i]=='+')
			{
				operand[opa++]=atoi(t.c_str());
				oper[op++]=s[i];
				t="";
			}
			else
			{
				t+=s[i];
			}
		}
		operand[opa++]=atoi(t.c_str());
		FOR(i,opa)
		{
			dpmin[i][i]=dpmax[i][i]=operand[i];
			
		}
		//cerr<<"OP "<<opa<<endl;;
		FORS(l,2,opa+1)
		{
			FORS(i,0,opa-l+1)
			{
				int j=i+l-1;
				dpmax[i][j]=-1;
				dpmin[i][j]=INF;
				FORS(k,i,j)
				{
					ll q=operation(dpmax[i][k],dpmax[k+1][j],k);
					//cerr<<"OP BW "<<dpmax[i][k]<<" "<<(char)(oper[k])<<" "<<dpmax[k+1][j]<<" = "<<q<<endl;
					ll qmin=operation(dpmin[i][k],dpmin[k+1][j],k);
					if(q>dpmax[i][j])dpmax[i][j]=q;
					if(qmin<dpmin[i][j])dpmin[i][j]=qmin;
				}
								
			}
		}
		cout<<"The maximum and minimum are "<<dpmax[0][opa-1]<<" and "<<dpmin[0][opa-1]<<"."<<endl;
		
	}
}
