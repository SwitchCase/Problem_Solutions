#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;
int main()
{
	int tc;
	int ca=0;
	string s;
	char in[22];
	scanf("%d",&tc);
	int n;
	int dig[10];
	while(ca++,tc--)
	{
		cin>>s;
		n=s.size();
		memset(in,0,sizeof in);
		memset(dig,0,sizeof dig);
		in[0]='0';
		for(int i=0;i<s.size();i++)in[i+1]=s[i];
		for(int i=0;i<n;i++)dig[in[i]-'0']++;
		bool pos=next_permutation(in,in+n+1);
		
		//for(int i=0;i<n+1;i++)printf("%c",in[i]);
		//cout<<endl;
		long long ans=0LL;
		if(pos)
		{
			printf("Case #%d: ",ca);
			int z=0;
			for(int i=0;i<n+1;i++)
			{
				if(z==0 && in[i]=='0'){continue;}
				else if(in[i]!='0'){z=1;printf("%c",in[i]);}
				else if(z)printf("%c",in[i]);
				
				
			}
			//printf("%lld",ans);
			printf("\n");
	
		}
		
		
	}
}
