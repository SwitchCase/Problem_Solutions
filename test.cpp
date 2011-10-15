#include<cstdio>
#include<iostream>
using namespace std;
#define TOTAL (sizeof(array)/sizeof(array[0]))

int array[]={1,2,3,4,5,6,7};
int main(){
	int d;
	printf("%d %u\n\n", TOTAL - 8,TOTAL-8);
	cout<<TOTAL-8<<endl;
	for(d=-1;d<=(TOTAL -2);d++)printf("%d\n",array[d+1]);
}
