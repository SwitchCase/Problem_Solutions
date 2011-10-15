
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
#include <fstream>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FORS(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a) for(int i=a;i>=0;i--)
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define MAX2(a,b) (a)<(b)?(b):(a)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define LEN(s) strlen(s)
#define tests(tc) int tc;scanf("%d",&tc);while(tc--)
#define TEN(n) (long long)pow(10LL,n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
/*
: 946321758  AND 946317825
COLL : 946321785  AND 946317852
COLL : 946381572  AND 946378125
COLL : 946528317  AND 946527831
COLL : 946572318  AND 946571832
COLL : 946583217  AND 946582731
COLL : 946731582  AND 946728135
COLL : 946752318  AND 946751832
COLL : 946853217  AND 946852731
COLL : 947132568  AND 947128635
COLL : 947132586  AND 947128653

*/

inline int digitsIn(ll n){int ans=0;while(n){n/=10;ans++;}return ans;}
using namespace std;

struct item
{
	string state;
	int h;
};

//map<string,int> dp;
queue<item> Q;
string arr[100001];
int dp[100000001];
int primes[20]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1};
int facts[11]={0};



int idx(string str)
{
	int n=10;
	int curr=0;
	int index=0;
	while(curr<9)
	{	
		cout<<" at n = "<<n<<"  "<<index<<endl;
		cout<<"curr fact multiple is "<<facts[n-1]<<endl;
		index+= (str[curr++]-'0')*facts[n--];
	}
	cout<<"INDEX FOR "<<str<<"  IS " <<index<<endl;
	cout<<"_________________"<<endl;
	return index;
}


void generate(string curr,int &n)
{
	//cerr<<"_______________________________________________"<<endl;
	//cerr<<" GEN FOR "<<curr<<endl;
	n=0;
	string temp=curr;
	FOR(i,9)
	{
			if((i+1)%3)
			{
				if(primes[(temp[i]-'0') + (temp[i+1]-'0')  ])
				{
					swap(temp[i],temp[i+1]);
				//	if(dp.find(temp)==dp.end()){
					arr[n++]=temp;
				//	cerr<<"GEN : "<<temp<<endl;
				//	}
					temp=curr;
				} 
			}
			if(i+3<9)
			{
				if(primes[(temp[i]-'0') + (temp[i+3]-'0')  ])
				{
					swap(temp[i],temp[i+3]);
					//if(dp.find(temp)==dp.end()){
					arr[n++]=temp;
					//cerr<<"GEN : "<<temp<<endl;
					//}
					temp=curr;
				} 
			}
	}
	//scerr<<"__________________________________________________"<<endl;
	//cin>>temp;
}
void init(string start,int h)
{
	
	int n;
	
	
	/*
	generate(start,n);
	//cerr<<" N IS "<<n<<endl;
	FOR(i,n)
	{
		cerr<<"calling for "<<arr[i]<<endl;
		if(dp.find(arr[i])==dp.end())
		{
			dp[arr[i]]=h+1;
			cerr<<" ADDED "<<arr[i]<<" = "<<h+1<<endl;
			init(arr[i],h+1);
			
		
		}
		else
		{
			 cerr<<"ALREADY ADDED : "<<arr[i]<<"  = "<<dp[arr[i]]<<" CURR = "<<h+1<<endl;
			 dp[arr[i]]=MIN2(dp[arr[i]],h+1);
			 
		}
		
	}
	*/
	item curr;
	curr.state=start;
	curr.h=0;
	Q.push(curr);
	int ch;
	while(!Q.empty())
	{
		item temp=Q.front();Q.pop();
		int index=idx(temp.state);
		if(dp[index]==-1)
		{
			
			dp[index]=temp.h;
			//dp[temp.state]=temp.h;
		}
		else
		{
			//dp[temp.state]=MIN2(dp[temp.state],temp.h);
			continue;
		}
		generate(temp.state,n);
		ch=temp.h;
		FOR(i,n)
		{
			temp.state=arr[i];
			temp.h=ch+1;
			Q.push(temp);
		}
	}
		
}

int main()
{
	memset(dp,-1,sizeof dp);
	facts[0]=1;
	FORS(i,1,11){facts[i]=facts[i-1]*i; cerr<<facts[i]<<endl;}
	//freopen(".//temp","w",stderr);
	string start="123456789";
	//init(start,0);
	string q="";
	int a;
	cout<<"DONE"<<endl;
	/*tests(tc)
	{
		q="";
		FOR(i,3)
		FOR(j,3){scanf("%d",&a);q+= (a+'0');}
		
		//cout<<"Q IS "<<q<<endl;
		int id=idx(q);
		//if(dp.find(q)!=dp.end())
		if(dp[id]!=-1)
		cout<<dp[id]<<endl;
		else cout<<"-1"<<endl;
	}*/
	cout<<"DONE"<<endl;
	tests(tc)
	{
		/*do
		{
			int index=idx(start);
			if(dp[index]==-1)dp[index]=atoi(start.c_str());
			else
			{
				cerr<<"COLL : "<<start<<"  AND "<<dp[index]<<endl;
			}
		}while(next_permutation(start.begin(),start.end())); 946321785  AND 946317852*/
		cout<<" ASD1 "<<idx("946321785")<<endl;
	cout<<" ASD2 "<<idx("946317852")<<endl;
	
	}
	
}
