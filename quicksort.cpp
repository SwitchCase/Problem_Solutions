// <-------------------[sWitCHcAsE]---------------------->
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<vector>
#include<map>
#include<cstring>
#include<cassert>
#include<queue>

#define FOR(i,n) for(i=0;i<n;i++)
#define FORS(i,a,n) for(i=a;i<n;i++)
#define ERR(x) cerr<<#x<<" "<<x<<endl
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
typedef long double ld;
 
#define MAX 100 
int arr[MAX]; 

int partition(int p, int q)
{
	if(p==q)return p;
	int i=p-1;
	int j=p;
	int pv=arr[q];
	int t;
	for(;j<q;j++)
	{
		if(arr[j] <= pv)
		{
			i++;
			t=arr[i];
			arr[i]=arr[j];
			arr[j]=t;
		}
	}
	t=arr[i+1];
	arr[i+1]=arr[q];
	arr[q]=t;
	return i+1;
	
}

void Qsort(int p,int q)
{
	if(p<q)
	{
		int r=partition(p,q);
		Qsort(p,r-1);
		Qsort(r+1,q);
	}
}



int main(int argc,char** args)
{
	int i,j,k;
  	FOR(i,MAX)
  	arr[i]=rand()%(MAX * MAX);
  	FOR(i,MAX)cout<<arr[i]<<" ";
  	cout<<endl;
  
  	Qsort(0,MAX -1);
  	FOR(i,MAX)cout<<arr[i]<<" ";
  	cout<<endl;
  
	  
 	
 	
}
