#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
char pattern[100004];
char dna[1000005];

//rand() function from cstdlib is used to generate pseudo-random numbers!
int main()
{
	int N=1000;//number of dna and pattern combinations !
	printf("%d\n",N);
	while(N--)
	{
	int s_MAX=1000000;//length of max input DNA
	int s_P=100000; // length of max pattern 
	char *allowed="AGTC";//the allowed chars in DNA seq.
	int lp,ls;
	ls=rand()%s_MAX;
	lp=rand()%s_P;
	if(lp>ls)
	{
		s_P=lp;
		lp=ls;
		ls=s_P;	
	}
	int i,j=0;
	int curr;
	char c;

	pattern[lp--]='\0';
	dna[ls--]='\0';
	int add=0;
	for(i=0;i<ls;i++)
	{
		curr=rand()%4;//%4 because only 4 chars are allowed in DNA seq.
		c=allowed[curr];
		dna[i]=c;
		if(i>(rand()%s_P)+12131 ||add) //to ensure that a valid pattern is generated every single time.
		{
			add=1;
			if(j<=lp)
				pattern[j++]=c;
		}
	}	
	printf("%s\n%s\n",dna,pattern);
	}
}
