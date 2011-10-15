#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<map>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define vp vector< pair<int,int> >
#define vvp vector< vp >
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef long long lli;
int __sign;
int __ch;
inline void S( int &x )
{
			x=0;
			while((__ch<'0' || __ch>'9') && __ch!='-' && __ch!=EOF)	__ch=getchar_unlocked();
			if (__ch=='-')
				__sign=-1 , __ch=getchar_unlocked();
			else
				__sign=1;
			
			do
				x=(x<<3)+(x<<1)+__ch-'0';
			while((__ch=getchar_unlocked())>='0' && __ch<='9');
			x*=__sign;
}
#define LIM 1001
int w[LIM];
//pii be[LIM];
struct piii
{	int first; int second; };
piii walk[LIM];
bool cmp(piii a, piii b)
{
	return a.first<a.second;
}
int main()
{
	int i,n,t,s,r,T,tc,x,a,b,len;
	double ans;
	S(T);
	for(tc=1;tc<=T;tc++)
	{
		scanf("%d%d%d%d%d",&x,&s,&r,&t,&n);
		len=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,w+i);
			walk[i].first=w[i];
			walk[i].second=b-a;
			len+=b-a;
		}
		sort(walk,walk+n,cmp);
		ans=0;
		
		if(t*r<=x-len)
		{
			for(i=0;i<n;i++)
			{
				ans+=((double)walk[i].second)/(s+walk[i].first);
			}
			printf("Case #%d: %f\n",tc,ans+(double)(x-len-t*r)/s+t);
		//	cout<<"Case #"<<tc<<": "<<ans+(double)(x-len-t*r)/s+t<<"\n";
			continue;
		}
		double runned=(double)(x-len)/r;
		double rem=t-runned;
		for(i=0;i<n;i++)
		{
			
			if(rem>0.0)
			{
				if(rem*(r+walk[i].first)>=walk[i].second)
				{
					ans+=(double)walk[i].second/(r+walk[i].first);
					rem-=(double)walk[i].second/(r+walk[i].first);
				}
				else
				{
					ans+=rem;
					ans+=((double)walk[i].second-rem*(r+walk[i].first))/(s+walk[i].first);
					rem=0;
				}
			}
			else
			{
				ans+=((double)walk[i].second)/(s+walk[i].first);
			}
		}
		printf("Case #%d: %f\n",tc,ans+runned);
	//	cout<<"Case #"<<tc<<": "<<ans+runned<<"\n";
	}
	return 0;
}
