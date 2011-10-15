// <-------------------[sWitCHcAsE]---------------------->
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<vector>
#include<map>
#include<cstring>
#include<cassert>
#include<queue>
#include<fstream>

#define FOR(i,n) for(int i=0;i<n;i++)
#define ERR(x) cerr<<#x<<" "<<x<<endl
#define pb push_back
using namespace std;
#define MAX 1000005

struct node
{
	int id;
	double xy[2];	
	//node(){id=-1,xy[0]=-1,xy[1]=-1;}
};

struct kdnode
{
	node data;
	kdnode *left,*right;
};
int c;
node arr[MAX];
int added[MAX];
node orig[MAX];

int dim;
int compare(const void *a,const void *b)
{
	if (((node*)a)->xy[dim] < ((node*)b)->xy[dim])return -1;
	else if(((node*)a)->xy[dim] > ((node*)b)->xy[dim])return 1;
	return 0;
}


kdnode* constructTree(int s,int e,int cdim)
{

	if(s>=c || e>=c || s>e || s<0 || e<0)return NULL;
	//cerr<<"CONS "<<s<<" "<<e<<endl;
	kdnode *curr=new kdnode;
	dim=cdim;
	//curr=NULL;
	/*
	if(s==e && !added[arr[s].id])
	{
		//cerr<<"ADDING "<<arr[s].id<<endl;
		curr->data=arr[s];
		curr->left=curr->right=NULL;
		added[arr[s].id]=1;
		return curr;
	}*/
	//arr=&(arr[0]);
	qsort(&arr[s],(e-s+1),sizeof(node),compare);
	//cerr<<"SORTING DONE"<<endl;
	int m=s+ (e-s+1)/2;
	//cerr<<"ADDING "<<arr[m].id<<endl;
	curr->data=arr[m];
	curr->left=curr->right=NULL;	
	//added[arr[m].id]=1;
	curr->left=constructTree(s,m-1,!cdim);
	curr->right=constructTree(m+1,e,!cdim);
	
	return curr;
	
}

double getD(node a,node b)
{
	return (a.xy[0]-b.xy[0])*(a.xy[0]-b.xy[0]) + (a.xy[1]-b.xy[1])*(a.xy[1]-b.xy[1]);
}


node s;
int comp_node(node a,node b)
{
	return getD(a,s) < getD(b,s);
}

void addNeighbour(vector<node> & neigh,node n,node source)
{
	//cerr<<"TRYING TO ADD "<<n.id<<" ";
	double dis=getD(n,source);
	//cerr<<"DIS TO SOURCE "<<dis<<" ";
	if(neigh.size()<3)
	{
		//cerr<<" ADDED !!!"<<endl;
		neigh.pb(n);
		s=source;
		sort(neigh.begin(),neigh.end(),comp_node);
	}
	else
	{
		if(getD(neigh[2],source)>dis)
		{	
			//cerr<<" ADDED "<<endl;
			//cerr<<"GOING TO REMOVE "<<neigh[2].id<<" and add "<<n.id<<endl;
			neigh[2]=n;
			s=source;
			sort(neigh.begin(),neigh.end(),comp_node);				
		}
	}
}

void NearestNeighbour(kdnode *curr, kdnode *source, vector<node>& best, int dim)
{
	
	if(source==NULL || curr==NULL)return;
	//cerr<<"NN FOR "<<curr->data.id<<endl;
	if(curr->right == NULL && curr->left==NULL && source->data.id !=curr->data.id)
	{
		
		addNeighbour(best,curr->data,source->data);
		return;
	}
	kdnode *near=NULL,*far=NULL;
	if(curr->right==NULL ||(source->data.xy[dim] < curr->data.xy[dim]))
	{
		near=curr->left;
		far=curr->right;
	}
	else
	{ 
		near=curr->right;
		far=curr->left;
	}
	NearestNeighbour(near,source,best,!dim);
	if(far!=NULL && (best.size()<3 || (source->data.xy[dim]-curr->data.xy[dim])*(source->data.xy[dim]-curr->data.xy[dim]) < getD(source->data,best[2]) ))
	{
		NearestNeighbour(far,source,best,!dim);
	}
	if(source->data.id !=curr->data.id)
		addNeighbour(best,curr->data,source->data);
}



void inorder(kdnode *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf(" %d ",root->data.id);
		inorder(root->right);
	}
	return;
}

int main(int argc,char* args[])
{
	//args[1]="inp.txt";
  freopen(args[1],"r",stdin);
    int id,x,y;
     c=0;
    while(scanf("%d",&id)!=EOF)
    {
    	arr[c].id=id;
     	added[c]=0;
    	scanf("%lf %lf",&arr[c].xy[0],&arr[c].xy[1]);
    	orig[c].xy[0]=arr[c].xy[0],orig[c].xy[1]=arr[c].xy[1],orig[c].id=arr[c].id;
    	c++;
    	
    	//cout<<arr[c-1].id<<" : "<<arr[c-1].xy[0]<<" "<<arr[c-1].xy[1]<<endl;
    	//cout<<"ITEMS "<<c<<endl;

    }
    //cout<<"ITEMS "<<c<<endl;
    kdnode *root;
    root=constructTree(0,c-1,0);
  //  inorder(root);
   // cout<<endl;
    FOR(i,c)
    {
    	vector<node> t;
    	kdnode source;
    	source.data=orig[i];
    	source.left=source.right=NULL;
    	NearestNeighbour(root,&source,t,0);
    	//cout<<"SIZE OF T"<<t.size()<<endl;
    	printf("%d %d,%d,%d\n",source.data.id,t[0].id,t[1].id,t[2].id);
    }
    
}
