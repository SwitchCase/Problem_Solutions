#include<stdio.h>

int primes[10000];

int sieve[500001];
int p=0;
void init()
{
	primes[p++]=2;
	for(int i=4;i<5000001;i+=2)sieve[i]=1;
	for(int i=3;i*i<=500001;i+=2)
	{
		if(sieve[i]==1)continue;
		else primes[p++]=i;
		int j=2;
		while(i*j<500001)
		{
			sieve[j*i]=1;
			j++;
		}
	}
}

int facts[500001];
int pr[]={2,3,5,7,11,13,17,19};
void calc()
{
	memset(facts,-1,sizeof facts);
	int t;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<500001;j++)
		{
			t=j;
			while(t%pr[i]==0)
			{
				
			}			
		}
	}
}
int main()
{
	int tc;
	scanf("%d",&tc);
	
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		if(sieve[n]==0){printf("1\n");continue;}
		int ans=1;
		
		for(int i=0;i<8;i++)
		{
			t=n;
			while(t%pr[i]==0)
			{
				
			}
		}
		
		if(ans==0)printf("0000\n");
		
		printf("%d\n",ans);
	}
}
