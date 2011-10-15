#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define FOR(i,a) for(int i=0;i<a;i++)
#define FORS(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a) for(int i=a;i>=0;i--)
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define MAX2(a,b) (a)<(b)?(b):(a)
#define LEN(s) strlen(s)
#define tests(tc) int tc;scanf("%d",&tc);while(tc--)
#define TEN(n) (long long)pow(10LL,n)
typedef long long ll;



using namespace std;

int val(int n,int& sign)
{
	int arr[10];
	int c=0;
	while(n)
	{
		arr[c++]=n%10;
		n/=10;
	}
	int ans=0;
	FORR(i,c-1)
	{
		ans+=arr[i]*sign;
		
		//cout<<(sign==-1?"-":"+")<<arr[i];
		sign*=-1;
		//cout<<(sign==-1?"-":"+");
	}
	//cout<<" = "<<ans<<endl;
	return ans;
}
int main()
{
	int sign=1;int ans=0;
	int a,b;
	while(1){
	scanf("%d",&b);
	sign=cd1;
	ans=0;
	if(b==0)break;
	FORS(i,0,b+1)
	{
		
		ans+=val(i,sign);
		/*
		
		FORS(j,TEN(i),TEN(i+1))
		{
			ans+=val(j,sign);
		}*/
		
	}cout<<"FOR "<<"  "<<ans<<endl;}
}
