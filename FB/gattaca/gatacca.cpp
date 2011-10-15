// <-------------------[sWitCHcAsE]---------------------->
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cassert>
#define MAX 1000005
#define FOR(i,n) for(int i=0;i<n;i++)
#define ERR(x) cerr<<#x<<" "<<x<<endl
using namespace std;
struct interval{
  int st;
  int fi;
  int w;
  interval(int s,int f,int wt):st(s),fi(f),w(wt){}
  interval(){st=0;fi=0;w=-1;}
};
interval arr[MAX];
int p[MAX];
int dp[MAX];
int best[MAX];
 
int m;
int comp1(const void* a,const void* b)
{
  
  interval *ia=(interval*)a;
  interval *ib=(interval*)b;
  if(ia->fi == ib->fi) return ia->st > ib->st;
  return ia->fi > ib->fi?1:-1;
}
 
int main(int argc,char** args)
{
    freopen(args[1],"r",stdin);
  //m is the number of intervals
  int n;
  scanf("%d",&n);
  //cout<<n<<endl;
  while(n)
  {
        scanf("%*s");
        if(n>=80)n-=80;
        else n=0;
    }
    //cout<<"N "<<n<<endl;
  scanf("%d",&m);
  m++;
  assert(m>0 && m<MAX);
  for(int i=1;i<m;i++)
  {
    scanf("%d %d %d",&arr[i].st,&arr[i].fi,&arr[i].w);
  }
  arr[0].st=0;
  arr[0].fi=0;
  arr[0].w=0;
 // cerr<<"READ COMPLETE"<<endl;
  qsort(&arr[0],m,sizeof (interval),comp1); 
 // cerr<<"SORTING DONE "<<endl;
  
  
  p[1]=p[0]=-1;
  int curr=arr[m].fi,currv=m;
  best[m]=currv;
  best[0]=-1;
  for(int i=m-1;i>0;i--)
  {
  	if( arr[i].fi!=curr)
  	{
        curr=arr[i].fi;
        currv=i;
    }
     best[i]=currv;
  }
  int lo,hi,mid,comp;
  //cerr<<"DOING SEARCH"<<endl;
  for(int i=1;i<m;i++)
  {
        curr=arr[i].st;
        lo=0;
        hi=i-1;
        comp=0;
        while(lo<hi)
        {
            mid=lo + (hi-lo+1)/2;
            if(arr[mid].fi>=curr)hi=mid-1;
            else lo=mid;
            if(arr[lo].fi>=curr)
            {
               comp=1;     
            }
        }
        if(comp)p[i]=-1;
        else p[i]=best[lo];
  } 
  
  //FOR(i,m)cerr<<arr[i].st<<" , "<<arr[i].fi<<" : "<<arr[i].w<<" p[i]= "<<p[i]<<" b[i]= "<<best[i]<<endl;
  FOR(i,m)dp[i]=0;
  FOR(i,m)
  {
  	if(p[i]<0)dp[i]=max(arr[i].w,(i>0?dp[i-1]:0));
  	else dp[i]=max(arr[i].w + dp[p[i]],dp[i-1]);
  }
 
  int ans=dp[m-1];
 
  printf("%d\n",ans);
}
