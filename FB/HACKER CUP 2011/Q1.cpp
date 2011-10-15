#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

int M[128][128];
char V[128][128];
int sx,sy,ex,ey;

int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};

int color[10][11111][2];

int main(){
	int T; scanf("%d",&T);
	while(T--){
		int R,C; scanf("%d%d",&R,&C);
		int clen[10]={0};
		for(int i=0;i<R;i++){
			char ch[128]; scanf("%s",ch); 
			//cerr<<"ch="<<ch<<"\n";
		   	for(int j=0;j<C;j++){
				V[i][j] = ch[j];
				M[i][j] = -1;
				if(V[i][j]=='S'){ sx=i; sy=j; }
				else if(V[i][j]=='E'){ ex=i; ey=j;  }
				else if(V[i][j]=='W'){ }
				else {
					int c = V[i][j]-'0';
					if(c){
						color[c][clen[c]][0]=i;
						color[c][clen[c]++][1]=j;
					}
				}
			}
		}
		//cerr<<"PROCESSING...\n";
		queue<pair<pair<int,int>,int> > Q;
		Q.push(make_pair(make_pair(ex,ey),0));
		while(!Q.empty()){
			pair<int,int> P = Q.front().first;
			int val = Q.front().second;
			int x = P.first; int y = P.second;
			cerr<<"Q: "<<x<<" "<<y<<" "<<val<<"\n";
			Q.pop();
			if(M[x][y]!=-1 || V[x][y]=='W') continue;
			M[x][y] = val;
			if(V[x][y]=='S') break;
			//cerr<<"Updating neighbors..\n";
			for(int i=0;i<4;i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx>=0 && nx<R && ny>=0 && ny<C){
					//cerr<<nx<<" "<<ny<<"\n";
					Q.push(make_pair(make_pair(nx,ny),val+1));
				}
			}
			//cerr<<"...\n";
			int c = V[x][y]-'0';
			if(V[x][y]!='E' && c>0){
				for(int i=0;i<clen[c];i++){
					int nx = color[c][i][0];
					int ny = color[c][i][1];
					//cerr<<nx<<" "<<ny<<"\n";
					Q.push(make_pair(make_pair(nx,ny),val+1));
				}
			}
			//cerr<<"done\n";
		}
		printf("%d\n",M[sx][sy]);
	}
}
