//<----------[sWitCHcAsE]----------->



#include<cstdio>

#include<iostream>

#include<cmath>

#include<algorithm>

#include<vector>

#include<map>

#include<queue>

#include<cstdlib>

#include<cstring>



using namespace std;



#define FOR(i,n) for(int i=0;i<n;i++)

#define pb push_back



typedef unsigned int uint;

typedef long long ll;

typedef unsigned long long ull;

/*

4

7000000 12000000 19000000 16000000 14000000 13000000 11000000 1000000 2000000 3000000 4000000 5000000 6000000 7000000 8000000

*/



ll pro[18][0xFFFF +10];

#define MOD 1000000007ll

int H;



inline ll MX(ll a,ll b) {

	if(a>b)return a;

	return b;

}

void print() {

	for(int i=0;i<H;i++){

		for(int j=0;j<(1<<i);j++)printf("%lld ",pro[i][j]);

		printf("\n");

	}

}

int main() {

	int sz;

	while(scanf("%d",&H),H) {

		

		for(int i=0;i<H;i++) {

			sz=(1<<i);

			for(int j=0;j<sz;j++) {

				scanf("%lld",&pro[i][j]);

				pro[i][j]%=MOD;

			}

		}

		for(int i=H-2;i>=0;i--) {

			sz=(1<<i);

			for(int j=0;j<sz;j++) {

				pro[i][j]= (pro[i][j]*(MX(pro[i+1][2*j],pro[i+1][2*j+1])))%MOD;

			}

		}

		//print();

		printf("%lld\n",pro[0][0]);

		

	}

}
