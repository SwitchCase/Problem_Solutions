
// <-------------------[sWitCHcAsE]---------------------->

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
#include <cmath>
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
#define TEN(n) (long long)pow(10.0,n)
typedef long long ll;
typedef unsigned long long ull;

inline int digitsIn(ll n){int ans=0;while(n){n/=10;ans++;}return ans;}
using namespace std;


ll ranged[16];
int signs[16];

ll doOdd(ll q,int dig)
{
	ll val=0LL;
	val+= 5LL*(q/10 - TEN(dig-2));
	//cout<<"1 "<<val;
	ll last,frst;
	last=q% TEN(dig-1);
	frst=q/TEN(dig-1);
	int s=-1 ;
	/*if((q+1)%2==0)
	{
		s=1;
	}
	else s=-1;*/
	//cout<<"VAL IS "<<val<<endl;
	while(1)	
	{
		//cout<<"Last "<<last<<" FRST "<<frst<<" ADDING TO VAL "<<frst*((last+1)%2)*s<<endl;
		val += frst*((last+1)%2)*s;
		q=last;
		dig--;
		if(dig==1)break;
		last=q% TEN(dig-1);
		frst=q/TEN(dig-1);
		s*=-1;
	}
	//cout<<"VAL B4 "<<val<<endl;
	s=1;
	for(int i=1;i<=last;i++,s*=-1)
	val+= i*s;
	//cout<<"VAL after "<<val<<endl;
	return val;
	
	
}


ll doEven(ll q,int dig)
{
	
	
	ll place=TEN(dig-2);
	int arr[16],ca,sign;
	ll val=0LL;
	ll DIG=dig,Q=q;
	ll last= q%place;
	dig=DIG;

	ca=dig-1;
	
	while(q)
	{
		arr[ca]=q%10;
	//	cout<<"ARR["<<ca<<"] is "<<arr[ca]<<endl;
		q/=10;
		ca--;
	}
	
	
	q=Q,dig=DIG;
	ca=1;
	sign=1;
	while(place)
	{
		val+= sign*arr[ca]* (last+1);
		val+= sign*(arr[ca]*(arr[ca]-1)/2)*place;
		place/=10;
		if(!place)break;
		ca++;sign*=-1;last=q%place;
	}
//	cout<<"PA 1 "<<val<<endl;
	//end of frst part
	
	place=TEN(dig-3);
	ca=1;
	ll factor=0;
	sign=-1;
	while(place)
	{
		factor=factor*10LL + arr[ca];
		val+=factor*(45LL*place)*sign;
		sign*=-1;place/=10;ca++;
	}
	//cout<<"PA 1.5 "<<val<<endl;
	
	last= Q%TEN(dig-1);
	val+= -1*arr[0]*(last+1);
//	cout<<"PA 2 "<<val<<endl;
	//end of part 2
	
	
	
	sign=-1;
	place = TEN(dig-1);
	ca=0;
	ll temp=sign*((arr[ca])*(arr[ca]-1)/2) *place;
	//cout<<" TEMP 1 "<<temp<<endl;
	val+= temp;
	place/=10;
	sign*=-1;
	ca++;
	/*
	while(ca<dig-2)
	{
		temp=sign* arr[ca]*place;
		cout<<" TEMP rest in while "<<temp<<endl;
		val+= temp;
		ca++;place/=10;sign*=-1;
	}
	*/
	temp= 45LL * (arr[0]-1)*place;
	val+=temp;
	//cout<<"VAL AT END OF 3 "<<val<<endl;
	return val;
	
	
	
	
}
int valed(int n,int& sign)
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
	ranged[0]=0LL;
	signs[0]=1;
	ranged[1]=5LL;
	signs[1]=-1;
	ranged[2]=-45LL;
	signs[2]=-1;
	FORS(i,3,16){ranged[i]=-10LL*ranged[i-1];signs[i]= (i%2)?signs[i-1]*-1:signs[i-1];}
	ll q,ans=0LL;
	while(1)
	{
		scanf("%lld",&q);
		if(q==0LL)break;
		int dig=digitsIn(q);
		
		FOR(i,dig){ans+=ranged[i];}
		if(dig%2)
		{
			if(dig<2)
			{
				int s=1;
				FORS(i,1,q+1){ans+= s*i;s*=-1;}
			}
			else ans+=doOdd(q,dig);
		}
		else 
		{
			if(dig<3)
			{
				int s=-1;
				FORS(i,10,q+1)ans+=valed(i,s);
			}
			else ans+=doEven(q,dig);
		}
		
		cout<<ans<<endl;ans=0LL;
	}
	

}
