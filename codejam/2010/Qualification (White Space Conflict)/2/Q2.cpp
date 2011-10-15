#include<cstdio>
#include<map>
#include<vector>
#include<cstring>
#include<iostream>

using namespace std;
bool visited[101][101];
int alts[101][101];
int basins[101][101];
int h,w;
int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

inline int valid(int r,int c)
{
	if(r>=0&&r<h && c>=0 && c<w)return 1;
	return 0;
}

int dfs(int r,int c,int bas)
{
	visited[r][c]=true;
	//basins[r][c]=bas;
	int mr,mc,min=9999999;
	int minr=-1,minc=-1;
	int i=0;
	while(i<4)
	{
		mr=r+dir[i][0];
		mc=c+dir[i][1];
		if(valid(mr,mc))
		{
			if(min>alts[mr][mc])
			{
				min=alts[mr][mc];
				minr=mr;
				minc=mc;
			}
		}
		i++;
	}
	if(minr!=-1 && minc!=-1 && alts[r][c]>alts[minr][minc])
	{
		//cout<<"calling "<<minr<<" "<<minc<<endl;
		if(basins[minr][minc]>0)return basins[r][c]=basins[minr][minc];
		else return basins[r][c]=dfs(minr,minc,bas);
		
	}
	else return basins[r][c]=r*w+c;
	
}


int main()
{
	int tc,cas=0;
	scanf("%d",&tc);
	while(cas++,tc--)
	{
		memset(visited,0,sizeof visited);
		memset(alts,0,sizeof alts);
		memset(basins,0,sizeof(basins));
		scanf("%d %d",&h,&w);
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				scanf("%d",&alts[i][j]);
			}
		}
		for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			if(!visited[i][j]){
		//	cout<<"calling from in "<<i<<" "<<j<<endl;
			basins[i][j]=dfs(i,j,w*i+j);}
		int vals[26];
		map<int,char> entry;
		memset(vals,-1,sizeof vals);
		char curr='a';
		vals[0]=basins[0][0];
		entry[basins[0][0]]='a';
		printf("Case #%d:\n",cas);
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				//printf("(%d)",basins[i][j]);
				if(entry.find(basins[i][j])!=entry.end())
				{
					printf("%c",entry[basins[i][j]]);
				}
				else
				{
					entry[basins[i][j]]= ++curr;
					printf("%c",entry[basins[i][j]]);
				}
				if(j!=w-1)printf(" ");
			}
			printf("\n");
		}
	}
}
