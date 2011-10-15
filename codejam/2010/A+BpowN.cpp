#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<memory>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#define VI vector<int>
#define VS vector<string>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FORS(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a,b) for(int i=a;i>=b;i--)
#define MAX2(a,b) ((a)>(b)?(a):(b))
#define MIN2(a,b) ((a)<(b)?(a):(b))
#define pow10(a) (int)pow(10.0,(a))
typedef unsigned int UI;

using namespace std;

struct Matrix2
{
	public:
	int a;
	int b;
	int c;
	int d;
	Matrix2()
	{
		this->a=0;
		this->b=0;
		this->c=0;
		this->d=0;
	
	}
	void mod(int m)
	{
		this->a%=m;
		this->b%=m;
		this->c%=m;
		this->d%=m;
	}
	void print()
	{
		printf("%d %d\n",this->a,this->b);
		printf("%d %d\n",this->c,this->d);
		printf("____________\n");
	}
};
Matrix2 mat;
void construct(int a, int b)
{
	mat.a=a;
	mat.b=b;
	mat.c=1;
	mat.d=a;
	//printf("%d %d = %d\n_______________\n",a,b,b-a*a);
	
}
void multiply(Matrix2 &m1,Matrix2 &m2)
{
	Matrix2 m3;
	m3.a= m1.a*m2.a + m1.b*m2.c;
	m3.b= m1.a*m2.b + m1.b*m2.d;
	m3.c= m1.c*m2.a + m1.d*m2.c;
	m3.d= m1.c*m2.b + m1.d*m2.d;
	m1.a=m3.a;
	m1.b=m3.b;
	m1.c=m3.c;
	m1.d=m3.d;
	return;
 }
int fast_exp(int n,int b,int m)
{
	Matrix2 temp;
	temp.a=1;temp.d=1;
	int f=0;
	for(int i=30;i>=0;i--)
	{
		
			multiply(temp,temp);
			temp.mod(pow10(m+1));
			temp.print();
		
		if(n&(1<<i))
		{
			f=1;
			multiply(temp,mat);
		temp.mod(pow10(m+1));
			printf("%d is 1\n",i);
			temp.print();
		}
		
		
	}
	return (2*temp.a + pow10(m)-1)%pow10(m) ; 
}
int main()
{
	int n,a,b,N,m;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d %d %d",&a,&b,&N, &m);
		construct(a,b);
		printf("construct\n");
		mat.print();
		printf("____________\n");
		printf("%d\n",fast_exp(N,b,m));
	}
	system("pause");
}
