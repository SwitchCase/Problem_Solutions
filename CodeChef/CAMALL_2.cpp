#include<cstdio>
#include<algorithm>

using namespace std;

struct item
{
	int val;
	int ind;
};

item items[1000001];
bool cmpi(const item a,const item b)
{
	return a.val<b.val;
}
int main()
{
	int t;
	scanf("%d",&t);
	int val;
	for(int i=0;i<t;i++){scanf("%d",&val);items[i].val=val;items[i].ind=i;}
	sort(items,items+t,cmpi);
	//for(int i=0;i<t;i++)printf("%d  %d\n",items[i].val,items[i].ind);
	
	int max=-1,ans=-1;
	for(int i=t-1;i>=0;i--)
	{
		if(items[i].ind>max)max=items[i].ind;
		else if (ans<max-items[i].ind)ans=max-items[i].ind;
	}
	if(ans==-1)printf("-1\n");
	else
	printf("%d\n",ans+1);
	
}
