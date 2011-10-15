//Problem :- Codechef-March -- K-important strings
//Method used :- DP
//Author :- Anshul Goyal

#include<stdio.h>
#include<string.h>
char str[151][301];
int diff[151][151];
int imp[501][151];
int prev[501][151];
int stac[501];
int L;

int main(){
	int t;
	int N, K, i,j,k,l;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&N,&L,&K);
		for(i=0;i<N;i++){
			scanf("%s",str[i]);
			imp[1][i]=L;
			}
		memset(diff,0,sizeof diff);
		//memset(stac,0,sizeof stac);
		for(i=0; i<N; i++){
			for(j=0;j<N;j++){
				for(k=1;k<L;k++){
					if(str[i][k]!=str[j][diff[i][j]])
					diff[i][j]=0;
					if(str[i][k]==str[j][diff[i][j]])
					diff[i][j]++;
					}
				diff[i][j]=L-diff[i][j];
				}
			}
		printf("---------------------------------------------\n");
		for(i=0;i<N;i++){
			for(j=0;j<N;j++)
				printf("%d ",diff[j][i]);
			printf("\n");
		}
		printf("---------------------------------------------\n");
		for(k=2;k<=K;k++)
		for(i=0;i<N;i++){
				imp[k][i]=imp[k-1][0]+diff[0][i];
				prev[k][i]=0;
				for(j=1;j<N;j++)
				if(imp[k][i]>imp[k-1][j]+diff[j][i]){
						imp[k][i]=imp[k-1][j]+diff[j][i];
						prev[k][i]=j;
						}
				}
		int pos=0,p,tmp;
		for(i=1;i<N;i++)
		if(imp[K][i]<imp[K][pos])
		pos=i;
		printf("%d\n",imp[K][pos]);
		
		i=0;p=pos,k=K;
		while(k>1){
			stac[i++]=p;
			p=prev[k--][p];
			}
		stac[i++]=p;j=i;
		printf("%s",str[stac[--i]]);
		for(k=2,i--;k<=K;i--){
			p=stac[i];
			printf("%s",str[p]+L-diff[prev[k][p]][p]);
			k++;
			}
		//printf("%s",str[pos]+L-diff[prev[K][pos]][pos]);
		printf("\n");
		
		tmp=0;
		printf("%d 0\n",stac[--j]);
		for(k=2,j--;k<=K;j--){
			p=stac[j];
			tmp+=diff[prev[k][p]][p];
			printf("%d %d\n",p,tmp);
			k++;
			}
		
		printf("\n");
		}
	return 0;
	}




