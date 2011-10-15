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

#define FOR(i,n) for(i=0;i<n;i++)
#define FORS(i,a,n) for(i=a;i<n;i++)
#define ERR(x) cerr<<#x<<" "<<x<<endl
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
typedef long double ld;
 
 

struct node
{
	int data;
	node * left,*right, *parent;
};

node* insert(node* root, int d)
{
	node *p;
	p=NULL;

		if(root==NULL)
		{
			root=(node*)malloc(sizeof(node));
			root->data=d;
			root->parent=p;
			root->left=NULL;
			root->right=NULL;
			return root;
		}
		else
		{	
			if(root->data == d)
			{
				cout<<"ALREADY EXISTS "<<endl;
				return NULL;
			}
			else
			{
				if(root->data > d)
				{
					p=root;
					root->left=insert(root->left,d);
					root->left->parent=p;
					return root;
				}
				else
				{
					p=root;
					root->right=insert(root->right,d);
					root->right->parent=p;
					return root;
				}
			}
		}
	return NULL;
}

node * search(node* root, int d)
{
	while(root!=NULL)
	{

		if(root->data==d)return root;
		else if(root->data > d) root=root->left;
		else root=root->right;
	}
	return root;
}
node *minimum(node *root,int d)
{
	node * st=search(root,d);
	while(st->left!=NULL)
		st=st->left;
	return st;
}

node* successor(node *root,int d)
{
	node *st=search(root,d);
	if(st->right !=NULL) return minimum(root,st->right->data);
	node *y=st->parent;
	while(y!=NULL  && y->right == st)
	{
		st=y;
		y=y->parent;
	}
	return y;
}

node * delete_node(node *root,int d)
{
	node *del=search(root,d);
	node *y,*x;
	if (del->left == NULL || del->right==NULL)
		y=del;
	else
	{
		 y=successor(root,del->data); 
		 cout<<"SUCCESSOR OF "<<del->data<<" is "<<y->data<<endl;
	}
	if (y->left !=NULL)
		x=y->left;
	else x=y->right;
	if(x!=NULL)x->parent=y->parent;
	if(y->parent==NULL)y=x; //y will be root for it to be true;
	else if (y== (y->parent)->left)
		(y->parent)->left=x;
	else (y->parent)->right=x;
	if(y!=del) del->data=y->data;
	return y;
}

void inorder(node *r)
{
	if(r!=NULL)
	{
		inorder(r->left);
		cout<<r->data<<" ";
		if(r->parent==NULL)cout<<"(NULL)"<<" ";
		else cout<<"("<<r->parent->data<<")"<<" ";
		inorder(r->right);
	}
}


int main(int argc,char** args)
{
  int i,j,k;
 
  node *root;
  root=NULL;
  root=insert(root,12);
  insert(root,100);
  insert(root,1000);
  insert(root,9);
  insert(root,33);
  insert(root,2);
  insert(root,0);
  insert(root,29);
  insert(root,35);
  insert(root,11);
  insert(root,6);
  
  
  inorder(root);cout<<endl;
  delete_node(root,33);
  inorder(root);cout<<endl;
  delete_node(root,0);
  inorder(root);cout<<endl;
  delete_node(root,11);
  inorder(root);cout<<endl;
  
 	 
 	
 	
}
