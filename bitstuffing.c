
// <-------------------[sWitCHcAsE]---------------------->

#include<stdio.h>

int main()
{

	int n;
	char q[32];
	scanf("%s",q);
	int s=0;
	char ans[32];
	int ac=0;
	int c=0;
	n=strlen(q);
	while(c<n)
	{
		if(q[c]=='1')
		{
			s++;
		}
		else
		{
			s=0;
		}
		ans[ac]= q[c];
		
		if(s==5)
		{
			ac++;
			ans[ac]='0';
			s=0;
		}
		c++;
		ac++;
	}
	ans[ac]='\0';
	//cout<<"OUT BIN "<<bin(ans)<<endl;
	printf("%s\n",ans);
}
