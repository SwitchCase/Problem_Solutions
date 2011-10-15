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

typedef long long ll;
#define MAX 10001

template <class T>inline void swap(T &a,T &b)
{
	T t=a;a=b;b=t;
}


using namespace std;

int ans[2][MAX];

int main()
{
	char s1[MAX],s2[MAX];
	while(1)
	{
		memset(ans,0,sizeof ans);
		
		cin.getline(s1,MAX);
		cin.getline(s2,MAX);
		if(s1=="" || s2=="")break;
		int t=0;
		int n1=LEN(s1),n2=LEN(s2);
		if(n1==0 && n2==0)break;
		FORS(i,1,n1+1)
		{
			
			
			FORS(j,1,n2+1)
			{
				if(s1[i-1]==s2[j-1])
				{
					ans[1][j]=1+ans[0][j-1];
				}
				else
				{
					
					ans[1][j]=MAX2(ans[0][j],ans[1][j-1]);
					
				}
			}
			memcpy(ans[0],ans[1],sizeof ans[1]);
		}
		
		cout<<ans[1][n2]<<endl;
		
	}
}
