#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

#include<map>
using namespace std;
typedef long double ld;
#define MAX 251
#define SIZE 21
string dp[SIZE][SIZE][MAX];
int nums[SIZE][SIZE];
int signs[SIZE][SIZE];

/*
1
3 5
2+1
+3+
5+2
5 3 2 9 6
*/

void call(int i,int j)
{	
	if(i%2==0 && j%2==0)return;
	else if(i%2==1 && j%2==1)return ;
	
	
}
bool compare(string s1,string s2)
{
	if(s1.size() < s2.size())return true;
	else if( s1.size() > s2.size())return false;
	else
	return !lexicographical_compare(s1.begin(),s1.end(),s2.begin(),s2.end());
}
int main()
{
	int tc,ca=0;
	scanf("%d",&tc);
	while(ca++,tc--)
	{
		int W,Q;
		memset(nums,0,sizeof nums);
		memset(signs,0,sizeof signs);
		for(int i=0;i<SIZE;i++)for(int j=0;j<SIZE;j++)for(int k=0;k<MAX;k++)dp[i][j][k]="";
		scanf("%d %d",&W,&Q);
		char c;
		for(int i=0;i<W;i++)
		{
			for(int j=0;j<W;j++)
			{
				if(i%2==0 && j%2==0)
				{
					scanf("%d",&nums[i][j]);
				}
				else if(i%2==1 && j%2==0){scanf("%c",&c);if(c=='+')signs[i][j]=1;else signs[i][j]=-1;}
				else if(i%2==0 && j%2==1){scanf("%c",&c);if(c=='+')signs[i][j]=1;else signs[i][j]=-1;}
				else scanf("%d",&nums[i][j]);
			}
			scanf("%*c");
		}
		int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
		
		/*
		for(int i=0;i<W;i++)
		{
			for(int j=0;j<W;j++)
			{
				if(i%2==0 && j%2==0 || i%2==1 && j%2==1)
				{
					printf("%d",nums[i][j]);
				}
				else printf("(%d)",signs[i][j]);
			}
			cout<<endl;
		}*/
		cout<<"Case #"<<ca<<": "<<endl;
		for(int i=0;i<W;i++)
		{
			for(int j=0;j<W;j++)
			{
				if((i%2==0 && j%2==0) || (i%2==1 && j%2==1))
				{
					for(int d=0;d<4;d++)
					{
						int di=i+dir[d][0],dj=j+dir[d][1];
						if(di>=0 && dj>=0 && di<MAX && dj<MAX)
						dp[di][dj][nums[i][j]]=(nums[i][j]+'0');	
						//cout<<"for "<<nums[i][j]<<" is "<<dp[nums[i][j]]<<endl;
					}
				}
			}
		}
		/*
		cout<<"*********************"<<endl;
		//system("pause");
		for(int i=0;i<MAX;i++)cout<<dp[i]<<endl;
		cout<<"********************\n";*/
		for(int i=0;i<W;i++)
		{
			for(int j=0;j<W;j++)
			{
				for(int d=0;d<4;d++)
				{
					if((i%2==0 && j%2==1) || (i%2==0 && j%2==1))continue;
					int si=i+dir[d][0];
					int sj=j+dir[d][1];
					if(si<W && sj<W && si>=0 && sj>=0)
					{
						for(int n=0;n<MAX;n++)
						{
							if(dp[si][sj][n]!="" && (n-(signs[si][sj]*nums[i][j])>=0 && n-(signs[si][sj]*nums[i][j])<MAX) )
							{
								if(dp[si][sj][n-(signs[si][sj]*nums[i][j])]!="")
								{
									string temp=dp[si][sj][nums[i][j]]+((signs[si][sj]>0?'+':'-') )+ dp[si][sj][n-(signs[si][sj]*nums[i][j])];
									
									//cout<<"TEMP :"<<temp<<"  = ";
								//	cout<<dp[si][sj][nums[i][j]]<<"     .+.      "<<((signs[si][sj]>0?'+':'-') )<<dp[si][sj][n-(signs[si][sj]*nums[i][j])];
								//	cout<<"EVAL TO :"<< n-(signs[si][sj]*nums[i][j]);
								//	cout<<"   B4  : "<<dp[si][sj][n]<<"  ";
									dp[si][sj][n]= compare(dp[si][sj][n],temp)?dp[si][sj][n]:temp;
								//  cout<<"AFTER COMPARE DP[N] = "<<dp[si][sj][n]<<endl;
								}
							}
							else
							{
								if(n-(signs[si][sj]*nums[i][j])>=0 && n-(signs[si][sj]*nums[i][j])<MAX && dp[si][sj][n-(signs[si][sj]*nums[i][j])]!=""){ 
										dp[si][sj][n]=dp[si][sj][nums[i][j]]+((signs[si][sj]>0?'+':'-') )+ dp[si][sj][n-(signs[si][sj]*nums[i][j])];
										//cout<<"ELSE "<<" n= "<<n<<" DP "<<dp[si][sj][n]<<endl;
									}
							}
			
						}
					}
		
				}
			}
		}
		//cout<<"6 "<<dp[6]<<endl;
		string ans="";
		int req;
		
		for(int q=0;q<Q;q++)
		{
			scanf("%d",&req);
			for(int i=0;i<W;i++)
			{
				for(int j=0;j<W;j++)
				{
					if(i%2==0 && j%2==1 || i%2==1 && j%2==0)
						if(ans!="" && dp[i][j][req]!="")ans=(compare(ans,dp[i][j][req])?ans:dp[i][j][req]);
						else ans=dp[i][j][req];
				}
			}
			cout<<ans<<endl;
			ans="";
		}
	}
}
