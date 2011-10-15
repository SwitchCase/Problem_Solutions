//Knuth-Morris-Pratt String Matching Algorithm.

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
 
void compute_prefix_function(char P[], int pi[])
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

void kmp_matcher(char T[], char P[])
{
	int n, m, i, q;
	int pi[20];

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
			printf("\nPattern occurs with shift %d", i-m+1);
			q = pi[q-1];
		}
	}
}

void main()
{

	char T[100],P[20];

	clrscr();
	printf("\nEnter the text: ");
	gets(T);
	printf("\nEnter the pattern: ");
	gets(P);

	kmp_matcher(T,P);
	getch();
}
