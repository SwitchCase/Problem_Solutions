#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

#include<map>
using namespace std;
typedef long double ld;
struct node
{
	string name;
	long double val;
	node *left;
	node * right;
	node(string n,long double v)
	{
		name=n;
		val=v;
	}
};

void build(string s,node *curr)
{
	sscanf();
}

int main()
{
	int tc;
	int ca=0;
	scanf("%d",&tc);
	string in;
	string com="";
	string s="";
	while(ca++,tc--)
	{
		int L;
		scanf("%d",&L);
		for(int i=0;i<L;i++){cin>>in;com+=in;}
		node *root=new node("",0.0);
		for(int i=1;i<com.size()-1;i++)
		{
			s+=com[i];
		}
		build(com,root);
	}
}

