
// <-------------------[sWitCHcAsE]---------------------->

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>

#define FOR(i,a) for(int i=0;i<a;i++)
#define FORS(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a) for(int i=a;i>=0;i--)
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define MAX2(a,b) (a)<(b)?(b):(a)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define LEN(s) strlen(s)
#define tests(tc) int tc;scanf("%d",&tc);while(tc--)
#define TEN(n) (long long)pow(10LL,n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

inline int digitsIn(ll n){int ans=0;while(n){n/=10;ans++;}return ans;}
using namespace std;

#define SIZE 4
#define DEFAULT {{1,4,2,0},{1,0,0,0},{0,1,0,0},{0,0,1,0}}
#define IDENTITY {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}
#define MOD 1000000007ll

void multiply(ll[SIZE][SIZE], ll[SIZE][SIZE],ll);
ll matrix[32][SIZE][SIZE]= {0};
ll ans[SIZE][SIZE]={0};
ll temp[SIZE][SIZE];
void print(ll mat[SIZE][SIZE]) {
	return;
	FOR(i,SIZE) {
		FOR(j,SIZE)cerr<<mat[i][j]<<" ";
		cerr<<endl;
	}
}

void multiply(ll mat[SIZE][SIZE], ll mat2[SIZE][SIZE],ll m)
{

	FOR(i,SIZE)FOR(j,SIZE) {temp[i][j]=mat[i][j];mat[i][j]=0;}

	//cerr<<"TEMP "<<endl;
	print(temp);
	//cerr<<"MAT 2"<<endl;
	print(mat2);
	FOR(i,SIZE) 
		FOR(j,SIZE)
			FOR(k,SIZE)
				mat[i][j]= (mat[i][j]+temp[i][k] * mat2[k][j])%MOD;
	
	//cerr<<"MAT AFTER "<<endl;
	//print(mat);
	//cerr<<"####################"<<endl;

}

/*
void square(ll mat[SIZE][SIZE],ll m)
{
	ll temp[SIZE][SIZE], mat2[SIZE][SIZE];
	FOR(i,SIZE)FOR(j,SIZE) {temp[i][j]=mat[i][j];mat2[i][j]=temp[i][j];mat[i][j]=0;}
	cerr<<"SQ SAYS "<<endl;
	cerr<<"TEMP "<<endl;
	print(temp);
	cerr<<"MAT 2"<<endl;
	print(mat2);
	FOR(i,SIZE) 
		FOR(j,SIZE)
			FOR(k,SIZE)
				mat[i][j]+= temp[i][j] * mat2[j][k];
	
	cerr<<"MAT AFTER "<<endl;
	print(mat);
	cerr<<"####################"<<endl;

}		
*/

void fast_exp(int n,ll m)
{
	ll d[SIZE][SIZE]= IDENTITY;
	ll temp[SIZE][SIZE]={0};
	//cerr<<"D VAL ORIG "<<endl;
	print(d);
	int ind=0;
	while(n) {
		if(n&1) multiply(d,matrix[ind],m);
		n>>=1;
		ind++;
	}
	FOR(i,SIZE)FOR(j,SIZE)ans[i][j]=d[i][j];
}

int getAns(int N) {
	ll m=MOD;
	fast_exp(N,m);
	//cerr<<"ANS "<<endl;
	//print(ans);
	return (ans[0][0]*11 + ans[0][1]*5 + ans[0][2]+ans[0][3])%MOD;
}

int main()
{
	ll m=1000000007ll;
	matrix[0][0][0]=1,matrix[0][0][1]=4,matrix[0][0][2]=2;
	matrix[0][1][0]=matrix[0][2][1]=matrix[0][3][2]=1;
	
	for(int i=1;i<32;i++) {
		for(int j=0;j<SIZE;j++) for(int k=0;k<SIZE;k++) matrix[i][j][k]=0;
		for(int j=0;j<SIZE;j++) for(int k=0;k<SIZE;k++) for(int m=0;m<SIZE;m++) 
			matrix[i][j][k]=(matrix[i][j][k] + matrix[i-1][j][m]*matrix[i-1][m][k])%MOD;
		//cerr<<"MAT "<<i<<endl;
		//print(matrix[i]);
		}
	tests(tc) {
		int n;
		scanf("%d",&n);
		if(n==1)printf("1\n");
		else if(n==2)printf("5\n");
		else {
			n-=3;
			printf("%d\n",getAns(n));
		}
	}
	return 0;
}
