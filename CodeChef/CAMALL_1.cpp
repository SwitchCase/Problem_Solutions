#include<cstdio>
#include<map>
#include<iostream>
#include<cstring>
typedef  long long ll;

/*
3
30 159754827191983291 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
123 532 126 236 423 462 456 23 744 568 235 764 234 465 234 678 43 236 887 897 991 230 450 650 345 67 42 45 60 999
30 1231425132131341
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
30 460
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/

//#define DEBUG 1
using namespace std;
int main()
{
	int tc;
	scanf("%d",&tc);
	int N;
	ll E;
	ll val[31];
	int a[31],b[31];
	while(tc--)
	{
		map<ll,int> hash;
		map<ll,int> hash2;
		scanf("%d %lld",&N,&E);
		for(int i=0;i<N;i++) scanf("%d",&a[i]);
		for(int i=0;i<N;i++) scanf("%d",&b[i]);			
		memset(val,0,sizeof val);
		val[0]=b[0];
		int size=0;
		for(int i=1;i<N;i++)
		{
			val[i]=val[i-1]*(ll)a[i]+(ll)b[i];
			if(val[i]<0 || val[i]>1000000000000000000LL )
			{
				val[i]=0;
				size=i;
				break;
			}
		#ifdef DEBUG
			cout<<i<<" : "<<val[i]<<endl;
		#endif	
		}
		#ifdef DEBUG
			cout<<"******************"<<endl;
		#endif
		//1st half
		
		N=size?size:N;
		int n=(1<<(N/2));
		ll curr=0;
		int temp;
		int pos=0;
		for(int i=0;i<n;i++)
		{
			 curr=0;
			 temp=i;
			 pos=0;
			while(temp)
			{
				if(temp&1)curr+=val[pos];
				pos++;
				temp>>=1;
			}
			hash[curr]=i;
		}
		n=1<<((N+1)/2);
		pos=0;
		int shift=((N)/2);
		for(int i=0;i<n;i++)
		{
			curr=0;
			temp=i;
			pos=0;
			while(temp)
			{
				if(temp&1)curr+=val[shift+pos];
				pos++;
				temp>>=1;
			}
			hash2[curr]=i;
		}
		map<ll,int>::iterator itr=hash.begin();
		ll tof;
		
		#ifdef DEBUG
			cout<<"hash1 has \n";
			for(;itr!=hash.end();itr++)cout<<(*itr).first<<"  "<<(*itr).second<<endl;
			cout<<"HASH 2 has\n";
			for(itr=hash2.begin();itr!=hash2.end();itr++)cout<<(*itr).first<<"  "<<(*itr).second<<endl;
			cout<<"_________________________\n";
			itr=hash.begin();
		#endif
		bool f=false;
		if(hash.find(E)!=hash.end())
		{
			cout<<"FOUND IN 1 : "<<hash[E]<<endl;
			continue;
		}
		else if(hash2.find(E)!=hash2.end())
		{
			cout<<"FOUND IN 2 : "<<hash2[E]<<endl;
			continue;
		}
		else
		{
			for(;itr!=hash.end();itr++)
			{
				ll t=(*itr).first;
				tof=E-t;
				if(hash2.find(tof)!=hash2.end())
				{
					cout<<"FOUND IN BOTH "<<hash[t]<<"  "<<hash2[tof]<<endl;
					
					f=true;
					break;
				}
			}
			
		}
		if(!f)cout<<"NOT FOUND\n";
	}
}
