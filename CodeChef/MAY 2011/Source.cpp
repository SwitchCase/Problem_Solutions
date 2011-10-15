#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;
typedef long double LD;
#define MOD 1000000007

LL M[32][4][4] = {0};

int F(int n){
    LL A[2][4][4] = {0};
    int usei = 0;
    for(int i=0;i<4;i++) A[usei][i][i]=1;
    int ind = 0;
    while(n){
        ind++;
        if(n&1){
            // A[!usei] = A[usei]*M[ind];
            for(int i=0;i<4;i++) for(int j=0;j<4;j++){
                A[!usei][i][j]=0;
                for(int t=0;t<4;t++)
                    A[!usei][i][j]= (A[!usei][i][j]+A[usei][i][t]*M[ind][t][j])%MOD;
            }
            usei = !usei;
        }
        n>>=1;
    }
    // A[use] is equal to M^n at this point.
    return (A[usei][0][0]*11 + A[usei][0][1]*5 + A[usei][0][2] + A[usei][0][3])%MOD;
}

int print(int ind){
	printf("%d\n",ind);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++) printf("%d ",M[ind][i][j]);
        printf("\n");
    }
}

int main(){
    // Prepare Matrix M
    for(int i=0;i<4;i++) M[0][i][i] = 1;
    M[1][0][0]=1; M[1][0][1]=4; M[1][0][2]=2; M[1][0][3]=0;
    M[1][1][0]=1; M[1][1][1]=0; M[1][1][2]=0; M[1][1][3]=0;
    M[1][2][0]=0; M[1][2][1]=1; M[1][2][2]=0; M[1][2][3]=0;
    M[1][3][0]=0; M[1][3][1]=0; M[1][3][2]=1; M[1][3][3]=0;
    //print(0); printf("\n");
    //print(1); printf("\n");
    for(int i=2;i<32;i++){
        // Square M[i-1] and store in M[i]
        for(int ai=0;ai<4;ai++) for(int aj=0;aj<4;aj++){
            M[i][ai][aj] = 0;
            for(int t=0;t<4;t++){
                M[i][ai][aj]= (M[i][ai][aj]+M[i-1][ai][t]*M[i-1][t][aj])%MOD;
            }
        }
        print(i); printf("\n");
    }
    int tc; scanf("%d",&tc);
    while(tc--){
        int n; scanf("%d",&n);
        if(n<2) printf("1\n");
        else if(n==2) printf("5\n");
        else if(n==3) printf("11\n");
        else {
            printf("%d\n",F(n-3));
        }
    }
}
