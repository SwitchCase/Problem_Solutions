
// <-------------------[sWitCHcAsE]---------------------->

#include<cstdio>
#include<map>
#include<iostream>
#include<cstring>
#include<algorithm>
typedef  long long ll;


//#define DEBUG 1
using namespace std;

ll val[35];

ll A[1<<17+1],B[1<<17+1];
int main()
{
		int N,a,b;
		ll ans=0;
		memset(A,0,sizeof A);
		memset(B,0,sizeof B);
		scanf("%d %d %d",&N,&a,&b);
		for(int i=0;i<N;i++) scanf("%lld",&val[i]);	
		#ifdef DEBUG
			cout<<"******************"<<endl;
		#endif
		//1st half
		int n=(1<<(N/2));
		ll curr=0;
		int temp;
		int pos=0;
		int s1=0,s2=0;
		int pA=0;
		#ifdef DEBUG
			cout<<"AA GAYA 1\n";
		#endif
		for(int i=0;i<n;i++)
		{
			 curr=0;
			 temp=i;
			 pos=0;
			while(temp)
			{
				if(temp&1)curr+=val[pos];
				pos++;
				temp>>=1;
			}
			A[pA++]=curr;
			s1++;
		}
		n=1<<((N+1)/2);
		pos=0;
		int pB=0;
		int shift=((N)/2);
		#ifdef DEBUG
			cout<<"AA GAYA 2\n";
		#endif
		for(int i=0;i<n;i++)
		{
			curr=0;
			temp=i;
			pos=0;
			while(temp)
			{
				if(temp&1)curr+=val[shift+pos];
				pos++;
				temp>>=1;
			}
			B[pB++]=curr;
			s2++;
		}
		sort(A,A+pA);
		sort(B,B+pB);
		#ifdef DEBUG
			cout<<"AA GAYA \n";
		#endif
		for(int i=0;i<pA;i++)
		{
			
			ans+=upper_bound(B,B+pB,(ll)b-A[i] )-lower_bound(B,B+pB,(ll)a-A[i]);
			
		}
		printf("%lld\n",ans);			
			
}
