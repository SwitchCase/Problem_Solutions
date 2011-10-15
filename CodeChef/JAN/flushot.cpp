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
 
int main(int argc,char** args)
{
	int i,j,k;
	int T;scanf("%d",&T);while(T--)
	{
		int n;
		double d,x;
		scanf("%d %lf",&n,&d);
		double ans1=0,ans2=0;
		double a;
		scanf("%lf",&a);
		FORS(i,1,n)
		{
			scanf("%lf",&x);
			ans1=max(ans1, (a+(i*d)-x));
			ans2=min(ans2, (a+(i*d)-x));
		}
		double diff,mm;
		double ans=0;
		
		if(ans1> (-1)*ans2)
		{
			diff=abs(ans1 + ans2);
			 mm=diff/2;
			if(a>mm)
			{
				ans1-=mm;
				ans2-=mm;
			}
			else
			{
				mm=a;
				ans1-=mm;
				ans2-=mm;
			}
			ans=max(max(mm,ans1),abs(ans2));
		}
		else if(ans1<(-1)*ans2)
		{
			diff=abs(ans1+ans2);
			mm=diff/2;
			if(a>mm)
			{
				ans1+=mm;
				ans2+=mm;
			}
			else
			{
				mm=a;
				ans1+=mm;
				ans2+=mm;
			}
			ans=max(max(mm,ans1),abs(ans2));
		}
		else ans=ans1;
		printf("%.4lf\n",ans);
		
	} 	
 	
}
