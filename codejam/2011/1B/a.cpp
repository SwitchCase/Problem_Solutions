// Author: Swarnaprakash
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>

using namespace std;

const int M = 105;
const int INF = 0x3f3f3f3f;
const bool debug=true;

#define SET(x,v)	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define SZ(x)		((int)((x).size()))
#define DB(x) 		if(debug) cout << #x << " : " << x <<endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

int main() {
	int tc;
	cin>>tc;
	for(int t=1;t<=tc;++t) {
		cout<<"Case #"<<t<<":\n";
		int n;
		cin>>n;
		string data[n];
		for(int i=0;i<n;++i)
			cin>>data[i];
		int played[n];
		int wins[n];
		SET(played,0);
		SET(wins,0);
		for(int i=0;i<n;++i)
			for(int j=0;j<SZ(data[i]);++j) {
				if(data[i][j] != '.') ++played[i];
				if(data[i][j] == '1') ++wins[i];
			}

		double wp[n];
		double owp[n];
		for(int i=0;i<n;++i) wp[i] = (double) wins[i]/(double)played[i];

		for(int i=0;i<n;++i) {
			owp[i] = 0.0;
			int op_count = 0;
			for(int j=0;j<n;++j) {
				if(data[i][j] == '.') continue;
				++op_count;
				int num = wins[j];
				int den = played[j];
				--den;
				if(data[j][i] == '1') --num;
				owp[i] += (double) num /den;
			}
			owp[i] /= op_count;
		}

		double oowp[n];
		for(int i=0;i<n;++i) {
			oowp[i] = 0.0;
			int op_count = 0;
			for(int j=0;j<n;++j) {
				if(data[i][j] == '.') continue;
				++op_count;
				oowp[i] += owp[j];
			}
			oowp[i] /= op_count;
		}


		for(int i=0;i<n;++i) {
			printf("%0.8f\n",0.25 * wp[i] + 0.50 * owp[i] + 0.25 * oowp[i]);
		}
	}
	return 0;
}

