#include<stdio.h>

int caller(int a) {
	int b=a*2;
	return a+b;
}

int main() {
	int i=caller(10);
	printf("%d",i);
	char *p="ashish";
	p[0]='v';
		
}
