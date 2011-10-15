
/*
10000
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define maxn 102
struct ss {
	int u, cost;
};

queue<ss>Q;
vector<int> links[maxn];

int N, S, maxx, res;
int Cost[maxn];


void BFS() {
	ss t, d;
	int i, v;
	t.u = S;
	t.cost = maxx = res = 0;
	Q.push(t);
	while(!Q.empty()) {
		t = Q.front();
		Q.pop();
		for(i = 0; i<links[t.u].size(); i++) {
			v = links[t.u][i];
			if(Cost[v] < (t.cost + 1)) {
				Cost[v] = t.cost + 1;
				d.u = v;
				d.cost = Cost[v];
				Q.push(d);
				if(maxx == d.cost && v < res){
					res = v;
				}
				if(maxx < d.cost){
					maxx = d.cost;
					res = v;
				}
			}
		}
	}
	cout<<"The longest path from "<<S<<" has length ";
	cout<<maxx<<", finishing at "<<res<<".\n";
}

void Cal() {
	if(N == 1) {
		cout<<"The longest path from 1 has length 0, finishing at 1.\n";
		return;
	}
	BFS();
}

void Free() {
	int i;
	for(i  = 1; i<= N; i++) {
		Cost[i] = 0;
		links[i].clear();
	}
}

int main() {
	int u, v, i, k = 1;
	//freopen("c:\\h.txt","r",stdin);
	while(cin>>N && N) {
		cin>>S;
		for(i = 0; i<1000000; i++) {
			cin>>u>>v;
			if(!u && !v) break;
			links[u].push_back(v);
		}
		cout<<"Case "<<k++<<": ";
		Cal();
		Free();
		cout<<endl;
	}
}


