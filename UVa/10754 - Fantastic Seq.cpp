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
//#define DEBUG
using namespace std;
typedef vector<int> VI;
typedef long long ll;
typedef long double ld;
typedef vector<vector<ll> > VLL;


struct Matrix{
	ll data[30][30];
};
ll C[30];
ll A[30];
Matrix mat;

int R;


Matrix MULTIPLY(Matrix a, Matrix b, int M)
{
	Matrix temp;
	int r,c,i,j,k;
	r=R;
	c=R;
	ll ans=0;
	FOR(i,r)
	{
		//temp.pb(vector<ll>());
		FOR(j,c)temp.data[i][j]=0;
	}

	FOR(i,r)
	{
		FOR(j,c)
		{
			ans=0ll;
			FOR(k,c)
			{
				ans+= a.data[i][k] * b.data[k][j];
				ans%=M;
			}
			temp.data[i][j]=ans;
		}
	}
	return temp;
}

Matrix power(Matrix A,ll N,ll M)
{
	if(N==1)return A;
	Matrix x=power(A,N/2,M);
	Matrix X=MULTIPLY(x,x,M);
	if(N%2)
	{
		return MULTIPLY(X,A,M);
	}
	else return X;
}


int main(int argc,char** args)
{
	int i,j;
	int tests;
	scanf("%d",&tests);
	ll K,m,n;
	while(tests--)
	{
		//cerr<<"DOING TEST"<<tests<<endl;
		//VLL mat;
		scanf("%lld %lld %lld",&K,&m,&n);
		FOR(i,K+1)
		{
			scanf("%lld",&C[i+1]);
			if(C[i+1]<0)
			{
				C[i+1] = (m* (-C[i+1]/m) + m + C[i+1])%m;
			}
		}
		FOR(i,K)
		{
			scanf("%lld",&A[i]);
			if(A[i]<0)
			{
				A[i] = (m* (-A[i]/m) + m + A[i])%m;
			}
		}
		if(n<K)
		{
			
			cout<<A[n]%m<<endl;
			if(tests!=0)cout<<endl;
			continue;
		}
		if(K==0)
		{
			printf("%lld\n",C[K+1]%m);
			if(tests!=0)cout<<endl;
			continue;
		}
		R=K+1;
		
		FOR(i,K+1)
		{
			mat.data[0][i]=(C[i+1]);
		}
		for(i=0;i<K-1;i++)
		{
			for(j=0;j<K+1;j++)
			{
				if(i==j)mat.data[i+1][j]=1;
				else mat.data[i+1][j]=0;
			}
		}
		for(i=0;i<K;i++)mat.data[K][i]=0;
		mat.data[K][K]=1;
		
		#ifdef DEBUG
			FOR(i,K+1)
			{
				FOR(j,K+1)printf("%lld ",mat.data[i][j]);
				printf("\n");
			}
		#endif
		
		Matrix ans=power(mat,n-K+1,m);
		ll final=0;
		vector<ll> RA;
		FOR(i,K)RA.pb(A[K-i-1]);
		RA.pb(1);
		#ifdef DEBUG
			
			FOR(i,RA.size())printf("%lld\n",RA[i]);
		#endif 
		FOR(i,R)
		{
			final+= (ans.data[0][i]* RA[i]) %m;
			final%=m;
		}
		cout<<(final%m)<<endl;
		if(tests!=0)cout<<endl;
	}
 	
 	
}
