// <-------------------[sWitCHcAsE]---------------------->
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<vector>
#include<map>
#include<cstring>
#include<cassert>
#include<queue>

#define FOR(i,n) for(i=0;i<n;i++)
#define FORS(i,a,n) for(i=a;i<n;i++)
#define ERR(x) cerr<<#x<<" "<<x<<endl
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
typedef long double ld;
 
#define MAX 999999
int glass[12];

/*int Q[MAX][2];
int h,t;
int insert(int p)
{
	t++;
	int loc=t;
	assert(t<MAX);
	Q[loc][0]=p;
	Q[loc][1]=t;
}

int exMin()
{
	int ret=Q[h][0];
	int retl=Q[h][1];
	Q[h][0]=Q[t][0];
	t--;
	
}*/

ll gcd(ll a,ll b)
{
	ll c;
	while(b!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}
struct compare
{
bool operator()(const ll& a, const ll& b)
{
	return a<b;
}
};
priority_queue<ll,vector<ll>,compare> Q;

int main(int argc,char** args)
{
	int i,j,k,n,a,b,c;
	int T;scanf("%d",&T);while(T--)
	{
		scanf("%d",&n);	
		FOR(i,n)
		{
			scanf("%d",&glass[i]);
			Q.push(glass[i]);
		}
		sort(glass,glass+n);
		cerr<<"TOP "<<Q.top()<<endl;
		ll prev=Q.top(),cnt=0,curr,ans;
		scanf("%d %d %d",&a,&b,&c);
		ans=prev;
		ll g;
		int ones=0;
		FOR(i,n)
		{
			FORS(j,i+1,n)
			{
				g=gcd(glass[i],glass[j]);	
				if(g==1)ones++;
			}
		}
		if(!ones)
		{
			printf("-1\n");
			continue;
		}
		while(1)
		{
		
			cerr<<"POPPED "<<prev<<endl;
			FOR(i,n)
			{
				Q.push(prev+glass[i]);
			}
			curr=Q.top();
			if(prev+1==curr)
			{
				cnt++;
				if(cnt>=glass[0])break;
			}
			else
			{
				cnt=0;
				ans=prev;
			}
			prev=curr;
			
		}
		cerr<<"ANS IS :"<<ans<<endl;
	}  
 	
 	
}
