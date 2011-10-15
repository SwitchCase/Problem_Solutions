#include<stdio.h>
#include<string.h>
#include<math.h>
#include<time.h>

#define MAX 1000005

int DEBUG;

//CALCULATE a raised to POWER b, modulo mod, in O(logn) time.
//Based on the fact that, for eg. 2^6 = 2^3 * 2^3. So by calculating it once we dont have to do it again!
//1ll is long long and is used because mod is of integer size and multiplying it twice, might cause overflow.
int power(int a,int b,int mod)
{
	if(b==0)return 1;
	int sqrt=power(a,b/2,mod)%mod;
	if(b%2) return (((1ll*a*sqrt)%mod)*(sqrt))%mod;
	else return (1ll*sqrt*sqrt)%mod;
}

void compute_prefix_function(char *P, int *pi)
{
	int m, k, q;

	m = strlen(P);
	pi[0] = 0;
	k = 0;

	for(q=1; q<m; q++)
	{
		while((k > 0) && (P[k] != P[q]))
			k = pi[k-1];
		if(P[k] == P[q])
			k = k+1;
		pi[q] = k;
	}
}

int kmp_matcher(char* T, char* P)
{
	int n, m, i, q;
	int pi[MAX];

	n = strlen(T);
	m = strlen(P);

	compute_prefix_function(P, pi);

	q = 0;
	for(i=0; i<n; i++)
	{
		while((q > 0) && (P[q] != T[i]))
			q = pi[q-1];
		if(P[q] == T[i])
			q = q+1;
		if(q == m)
		{
			if(DEBUG)printf("KMP Pattern occurs with shift %d\n", i-m+1);
			q = pi[q-1];
			return (i-m+1);
		}
	}
	if(DEBUG)	printf("KMP NOT FOUND\n");
	return -1;
}




int Rabin_Karp(char *S,char *N)
{
	int T[MAX],P[MAX],n,m,d,q,p,h,t,i,s;
    n=strlen(S);
    m=strlen(N);
	//clrscr();
	//printf("Program to implement Rabin-Karp Algorithm \n.... Being run on the input \n");
	i=n;
	while(i--)
	{
    	if((S[i]=='A')||(S[i]=='a'))
    	    T[i]=1;
        else if((S[i]=='G')||(S[i]=='g'))
            T[i]=2;
        else if((S[i]=='T')||(S[i]=='t'))
            T[i]=3;
        else if((S[i]=='C')||(S[i]=='c'))
            T[i]=4;
        else  
        {

        	if(DEBUG)printf("the pattern is not DNA");
            return -2;
            i++;
  		}                   
	}
	i=m;
	while(i--)
	{
    	if((N[i]=='A')||(N[i]=='a'))
    	    P[i]=1;
        else if((N[i]=='G')||(N[i]=='g'))
            P[i]=2;
        else if((N[i]=='T')||(N[i]=='t'))
            P[i]=3;
        else if((N[i]=='C')||(N[i]=='c'))
            P[i]=4;
        else  
        {
	        if(DEBUG)printf("the pattern is not DNA");
        	return -2;
 		}
 	}
	d=10;
	q=13;
	p=0;
	t=0;
	h = power(10,m-1,q);
	//printf("DOING PREPRO\n");
	for (i=0; i<m; i++)	//Preprocessing
	{
		p = (d * p + P[i]) % q;
		t = (d * t + T[i]) % q;
	}
	//printf("DOING MATCH\n");
	for (s=-1; s<n-m; s++)	//Matching
	{
		if (p == t)
			if(!strncmp(N, S+s+1, m))
			{
				if(DEBUG)printf("ROBIN KARP Pattern occurs with shift : %d  ", s+1);
				return s+1;
			}
		if(s < n-m)
		{
			t = (d * (t - T[s+1] * h) + T[s+m+1]) % q;
			if(t < 0)
				t = q + t;
		}
	}
//	scanf("%d",&i);
//	getch();
	if(DEBUG)printf("NOT FOUND \n");
	return -1;
}


int main(int argc,char* args[])
{

	//HANDLE THE COMMAND LINE ARGUMENTS.
	if(argc<=1)
	{
		printf("WRONG USAGE!\nCorrect Usage: file_name [-d]\nFLAGS:  d - DEBUG MODE\nIgnores all other flags\n");
		return 1;
	}
	char *filename=NULL;
	
	DEBUG=0;
	for(int i=1;i<argc;i++)
	{
		if( !strcmp("-d",args[i]))
		{
			DEBUG=1;
			break;
		}
		else DEBUG=0;
	}
	
	for(int i=1;i<argc;i++)
	{
		if( strcmp("-d",args[i]))
		{
			filename=args[i];
			break;
		}
	}
	if(filename==NULL)
	{
		printf("WRONG USAGE!\nCorrect Usage: file_name [-d]\nFLAGS:  d - DEBUG MODE\nIgnores all other flags\n");
		return 1;
	}
	//COMMAND LINE ARGS END.
	//REDIRECT THE FILE TO THE STANDARD INPUT.
	freopen(filename,"r",stdin);
	int n;
	scanf("%d",&n);
	int t=n;
	char dna[MAX],pattern[MAX];
	double kmp=0,rabin=0;
	time_t curr,after;
	int r,k;
	//LOOOP T TIMES
	while(t--)
	{
		scanf("%s %s",dna,pattern);
		//printf("LEN OF DNA %d and pattern %d\n",strlen(dna),strlen(pattern));
		curr=time(NULL);
		r=Rabin_Karp(dna,pattern);//RUN RABIN KARP ON THE INPUT
		after=time(NULL);
		rabin+=difftime(after,curr)*1000;//CALCULATE TIME TAKEN AND ADD TO TOTAL
		curr=time(NULL);
		k=kmp_matcher(dna,pattern);//RUN KMP.
		after=time(NULL);
		kmp+=difftime(after,curr)*1000;//CALCULATE TIME TAKEN.
		if(r!=k) //MAKE SURE THAT THE ALGORITHMS BOTH RETURN THE SAME OUTPUTS.
		{
			printf("ANSWERS NOT MATCHING !! for case %d\n",t);
		}

	}
	printf("TIME TAKEN BY RABIN KARP %lf milliseconds...\n",rabin);
	printf("TIME TAKEN BY KMP %lf milliseconds ...\n",kmp);
	printf("PERCENTAGE INCREASE IN KMP %lf%% \n",(rabin-kmp)/kmp *100);//SHOW % CHANGE!
	
	
}
