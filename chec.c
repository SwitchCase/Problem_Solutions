#include<stdio.h>
#include<stdlib.h>

//struct node;
struct node
{
	struct node *next;
	int data;
};

void insert(struct node *root,int k)
{
	while(root->next !=NULL)
	{
		root=root->next;
	}
	struct node *child=(struct node*)malloc(sizeof(struct node));
	child->data=k;
	child->next=NULL;
	root->next=child;
}

void print(struct node *root )
{
	while(root->next!=NULL)
	{
		printf("%d ",root->data);
		root=root->next;
	}
	printf("%d\n",root->data);
}

void delete(struct node *root,int a)
{
	struct node *orig=root;
	while(root!=NULL && root->data!=a)root=root->next;
	printf("add %u %u \n",root,root->next);
	root=root->next;
	printf("add %u %u \n",root,root->next);
	print(orig);
}
int main(int argc,char** args)
{
	int i,j,k;
	struct node *t=(struct node*)malloc(sizeof(struct node));
	t->data=10;
	t->next=NULL;
	insert(t,100);
	insert(t,2000);
	insert(t,1001);
	insert(t,1);
	print(t);
	delete(t,2000);
	print(t);
		 	
 	
}
