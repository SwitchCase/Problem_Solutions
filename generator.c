#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int main()
{
	int s_MAX=10000000;
	int s_P=100000;
	char *allowed="AGTC";
	int lp,ls;
	ls=rand()%s_MAX;
	lp=rand()%s_P;
	if(lp>ls)
	{
		s_P=lp;
		lp=ls;
		ls=s_P;	
	}
	//printf("%d %d",ls,lp);
	//freopen("dna.txt","w",stdout);
	int i,j=0;
	int curr;
	char c;
	char pattern[1000004],dna[10000005];
	pattern[lp--]='\0';
	dna[ls--]='\0';
	int add=0;
	for(i=0;i<ls;i++)
	{
		curr=rand()%4;
		c=allowed[curr];
		dna[i]=c;
		if(i>s_P+12131 ||add)
		{
			add=1;
			if(j<=lp)
				pattern[j++]=c;
		}
	}	
	printf("%s\n%s",dna,pattern);
}
