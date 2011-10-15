#include<stdio.h>
#define TOTAL (sizeof(array)/sizeof(array[0]))

int array[]={1,2,3,4,5,6,7};
int main(){
	int d;
	printf("%d %u", TOTAL - 8,TOTAL-8);
	for(d=-1;d<=(TOTAL -2);d++)printf("%d\n",array[d+1]);
}
