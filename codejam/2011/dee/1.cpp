#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int T; scanf("%d",&T);
    for(int i=1;i<=T;i++){
        int N; scanf("%d",&N);
        int time[2] = { 0, 0 };
        int pos[2]  = { 1, 1 };
        int t=0;
        while(N--){
            char c; int next, col;
            scanf(" %c %d",&c,&next);
            if(c=='O') col=0; else col=1;
            int need = abs(next-pos[col]);
            need -= (t-time[col]); if(need<0) need=0;
            t +=  need+1;
            time[col] = t; pos[col] = next;
            //printf("%c:%d pressed at t=%d\n",c,next,t);
        }
        printf("Case #%d: %d\n",i,t);
    }
}
