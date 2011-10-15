#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int n;
char inp[1024];
int dfsn[102];
int low[102];
int timed;
int ans[101];
vector<vector<int> > graph;

inline vector<string> split(string s,char* tok){vector<string> vs;char *pch;char *q= (char*)s.c_str();	pch=strtok(q," ");	while(pch !=NULL){vs.push_back(string(pch));pch=strtok(NULL,tok);}return vs;}

void dodfs(int ind)
{
 timed++;
 dfsn[ind]=timed;
 int min=dfsn[ind];
 low[ind]=dfsn[ind];
 int child=0;
 int v;
 for(int i=0;i<graph[ind].size();i++)
 {
  v=graph[ind][i];
  if(dfsn[v]==0)
  {
   dodfs(v);
   child++;
   low[ind]= low[ind]<low[v]?low[ind]:low[v];
   if(dfsn[ind]==1)
   {
    if(child>=2)
    {
     ans[ind]=1;

    }
   }
   else if(low[v]>=dfsn[ind])
   {

    ans[ind]=1;

   }

  }
  else if(dfsn[v]<dfsn[ind]-1)
  {
   low[ind]=low[ind]<dfsn[v]?low[ind]:dfsn[v];
  }
 }

}

int main()
{
 int ind,tem;
 int s;
 while(1)
 {
  cin.getline(inp,sizeof inp);
  sscanf(inp,"%d",&n);
  timed=0;
  memset(ans,0,sizeof ans);
  graph.clear();
  for(int i=0;i<n;i++)
  {
   vector<int> temp;
   graph.push_back(temp);
  }
  if(n==0)break;
  vector<string> in;
  fflush(stdin);
  for(int i=0;i<n;i++)
  {

   cin.getline(inp,sizeof inp);

   in=split(string(inp)," ");
   if(in[0]=="0")break;

   sscanf(in[0].c_str(),"%d",&ind);
   vector<int> vt;
   for(int i=1;i<in.size();i++)
   {
    sscanf(in[i].c_str(),"%d",&tem);
    graph[tem-1].push_back(ind-1);
    vt.push_back(tem-1);
   }
   graph[ind-1]=vt;
  }
  memset(dfsn,0,sizeof dfsn);
  dodfs(ind-1);
  int a=0;
  for(int i=0;i<n;i++)
  {
   if(ans[i])a++;
  }

  cout<<a<<endl;
 }
}
