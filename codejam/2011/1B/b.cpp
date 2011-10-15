/*
ID: imranka1
PROG: test
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <queue>
#include <cstring>
#include <fstream>
using namespace std;
#define all(x) (x).begin(),(x).end()

#define vs vector <string>
#define vi vector <int>
#define p(X) push_back((X))

#define fir(i,j,n) for(int (i)=(j);(i)<(n);(i)++)
#define fire(i,j,n) for(int (i)=(j);(i)<=(n);(i)++)
#define firr(i,j,n) for(int (i)=(j);(i)>(n);(i)--)
#define firre(i,j,n) for(int (i)=(j);(i)>=(n);(i)--)
#define tr(v,it) for(typeof(v.begin()) it=v.begin();it!=v.end();it++)

#define srt(v) sort((v).begin(),(v).end())
#define srtc(v) sort(v.begin(),v.end(),cmp)

#define _bc(i) __builtin_popcount(i)

string lower(string s) {for(int i=0;i<s.size();i++) s[i]=tolower(s[i]);return s;}
vector<string> sep(string s,char c) { string temp;vector<string> res;for(int i=0;i<s.size();i++) { if (s[i]==c) {if (temp!="") res.push_back(temp);temp="";continue;}temp=temp+s[i];}if (temp!="") res.push_back(temp);return res;}
template<class T> T toint(string s)
{
	stringstream ss(s);
	T ret;
	ss>>ret;
	return ret;
}
template<class T> string tostr(T inp)
{
	string ret;
	stringstream ss;ss<<inp;
	ss>>ret;
	return ret;
}

int P[201];
int V[201];
int C, D;
#define EPS 1e-6
bool test(double tim)
{
	double mn = -1e15;
	fir(i, 0, C)
	{
		double tmin = (double)P[i] - tim;
		tmin = max(tmin, mn);
		tmin += ((double)V[i] - 1.) * (double)D;
		double diff = fabs(tmin - (double)P[i]);
		if (diff - tim > EPS)
			return false;
		mn = tmin + D;
	}
	return true;
}

int main() {
	int T;
	cin>>T;
	int kase = 0;
	while(T--)
	{
		kase++;
		printf("Case #%d: ", kase);
		cin>>C>>D;
		fir(i, 0, C) cin>>P[i]>>V[i];
		double lo = 0, hi = 1e15;
		fir(i, 0, 300)
		{
			double md = (lo + hi)/2.;
			if (test(md))
				hi = md;
			else
				lo = md;
		}
		printf("%.6lf\n", (lo + hi)/2.);
	}
    return 0;
}
