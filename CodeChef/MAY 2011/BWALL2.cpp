
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
#define BOOST 256

void multiply(ll[SIZE][SIZE], ll[SIZE][SIZE],ll);
ll matrix[BOOST+5][SIZE][SIZE]= {0};
ll matrix_32[32][SIZE][SIZE]= {0};
ll ans[SIZE][SIZE]={0};
ll temp[SIZE][SIZE];
void print(ll mat[SIZE][SIZE]) {
	//return;
	FOR(i,SIZE) {
		FOR(j,SIZE)cerr<<mat[i][j]<<" ";
		cerr<<endl;
	}
}

void multiply(ll mat[SIZE][SIZE], ll mat2[SIZE][SIZE],ll m)
{

	FOR(i,SIZE)FOR(j,SIZE) {temp[i][j]=mat[i][j];mat[i][j]=0;}
	cerr<<"MULTIPLYING - "<<endl;
	cerr<<"TEMP "<<endl;
	print(temp);
	
	cerr<<" - and MAT 2"<<endl;
	print(mat2);
	FOR(i,SIZE) 
		FOR(j,SIZE)
			FOR(k,SIZE)
				mat[i][j]= (mat[i][j]+temp[i][k] * mat2[k][j])%MOD;
	
	cerr<<"which is equal to "<<endl;
	print(mat);
	cerr<<"####################"<<endl;

}


void fast_exp(int n,ll m)
{
	ll d[SIZE][SIZE]= IDENTITY;
	ll temp[SIZE][SIZE]={0};
	//cerr<<"D VAL ORIG "<<endl;
	print(d);
	int ind=0;
	while(n) {
		if(n&1) multiply(d,matrix_32[ind],m);
		n>>=1;
		ind++;
	}
	FOR(i,SIZE)FOR(j,SIZE)ans[i][j]=d[i][j];
}

void fast_exp2(int n,ll m) {
	ll d[SIZE][SIZE]= IDENTITY;
	//cerr<<"D VAL ORIG "<<endl;
	print(d);
	int ind=0;
	while(n) {
		cerr<<"MULTIPYING WID "<<(n&(BOOST-1))<<" wid n= "<<n<<" boosting by "<<BOOST<<endl;
		multiply(d,matrix[(n & (BOOST-1))],m);
		n/=BOOST;
	}
	FOR(i,SIZE)FOR(j,SIZE)ans[i][j]=d[i][j];
}
int getAns(int N) {
	cerr<<"PROCESSING FOR "<<N<<endl;
	ll m=MOD;
	fast_exp2(N,m);
	//cerr<<"ANS "<<endl;
	//print(ans);
	return (ans[0][0]*11 + ans[0][1]*5 + ans[0][2]+ans[0][3])%MOD;
}

int main()
{
	ll m=1000000007ll;
	
	matrix_32[0][0][0]=1,matrix_32[0][0][1]=4,matrix_32[0][0][2]=2;
	matrix_32[0][1][0]=matrix_32[0][2][1]=matrix_32[0][3][2]=1;
	for(int i=1;i<32;i++) {
		for(int j=0;j<SIZE;j++) for(int k=0;k<SIZE;k++) matrix_32[i][j][k]=0;
		for(int j=0;j<SIZE;j++) for(int k=0;k<SIZE;k++) for(int m=0;m<SIZE;m++) 
			matrix_32[i][j][k]=(matrix_32[i][j][k] + matrix_32[i-1][j][m]*matrix_32[i-1][m][k])%MOD;
		//cerr<<"MAT "<<i<<endl;
		//print(matrix[i]);
		}
	
	
	for(int i=0;i<SIZE;i++)matrix[0][i][i]=1;
	
	
	
	for(int i=1;i<=BOOST;i++) {
		fast_exp(i,MOD);
		for(int j=0;j<SIZE;j++)for(int k=0;k<SIZE;k++)matrix[i][j][k]=ans[j][k];
		cerr<<"FOR "<<i<<endl;print(matrix[i]);
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
