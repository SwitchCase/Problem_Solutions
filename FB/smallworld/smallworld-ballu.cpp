#include<iostream>
#include<vector>
#include<map>
#include<fstream>
#include<algorithm>
using namespace std;
int D=0;
map<int,int> countMap;
struct node{
	int id;
	double crd[2];
	
};
struct kdnode{
	int axis;
	node nd;
	kdnode *left,*right;
};
int CMP(node a,node b){
	return a.crd[D]<b.crd[D];
}
vector<node> getSubArr(vector<node> arr,int median,int side){
	vector<node> ret;
	int start,end;

if(side == 0){	
	start=0;
	end=median-1;
	}
else
	{
	start=median+1;
	end=arr.size()-1;
	}
	for(int i=start;i<=end;i++){
		ret.push_back(arr[i]);
	}
return ret;
}
kdnode* createKDtree(vector<node> arr,int depth){
	/*
If exset is empty then return the empty kdtree
Call pivot-choosing procedure, which returns two values:
ex := a member of exset
split := the splitting dimension
d := domain vector of ex
exset' := exset with ex removed
r := range vector of ex
exsetleft := f(d r ) 2 exset' j d split dsplit g

exsetright := f(d r ) 2 exset' j d split > dsplit g

kdleft := recursively construct kd-tree from exsetleft
kdright := recursively construct kd-tree from exsetright
kd := < d r split kdleft kdright >
By induction on the length of exset and the

kya nautanki hai!!
	*/
	if(arr.size() == 0)
		return NULL;
	
	kdnode* ptr= new kdnode;
	ptr->axis=depth%2;
	D=depth%2;
	//
	sort(arr.begin(),arr.end(),CMP);
	int median=arr.size()/2;
	node nd=arr[arr.size()/2];
	ptr->nd=nd;
	if(countMap.count(nd.id) == 0){
		countMap[nd.id]=1;
	}
	else
	{
		cout<<"already inserted  "<<nd.id<<"\n";
	}
	ptr->left=NULL;
	ptr->right=NULL;
	vector<node> leftarr=getSubArr(arr,median,0);
	vector<node> rightarr=getSubArr(arr,median,1);
	ptr->left=createKDtree(leftarr,depth+1);
	ptr->right=createKDtree(rightarr,depth+1);
	
	//
	return ptr;
}
void inorder(kdnode *qaz){
	if(qaz==NULL){
	return;
	}
	else
	{
		inorder(qaz->left);
		cout<<qaz->nd.id<<" ";
		inorder(qaz->right);
	}
}
int depth(kdnode* qaz){
	if(qaz==NULL){
		return 0;
	}
	else
		return 1+max(depth(qaz->left),depth(qaz->right));
}
int count(kdnode* qaz){
	if(qaz==NULL){
		return 0;
	}
	else
		return 1+count(qaz->left)+count(qaz->right);
}
struct holder{
	int id;
	double distance;
	
};
double getDistance(node n1,node n2){
	return (n1.crd[0]-n2.crd[0])*(n1.crd[0]-n2.crd[0])+(n1.crd[1]-n2.crd[1])*(n1.crd[1]-n2.crd[1]);
}
int CMP2(holder x,holder y){
	return x.distance < y.distance;
}
void addTarget(vector<holder>& nearest,node insert,node arr){
		holder temp;
		temp.id=insert.id;
		temp.distance=getDistance(insert,arr);
		bool exists=false;
		//this is probabaly unncessary,remove it later
		for(int i=0;i<nearest.size();i++){
			if(nearest[i].id == insert.id)
				{
					exists=true;
					break;
				}
		}
		if(exists == true)
			return;
if(nearest.size()<3)
	{
		nearest.push_back(temp);
		if(arr.id==10 && temp.id==15)
		{
			for(int i=0;i<nearest.size();i++)cout<<"::: "<<nearest[i].id<<endl;
		}
		sort(nearest.begin(),nearest.end(),CMP2);
	}
else
	{
		if(temp.distance < nearest[2].distance)
			{nearest[2]=temp;
				if(arr.id==10 && temp.id==15)
		{
			for(int i=0;i<nearest.size();i++)cout<<"::: "<<nearest[i].id<<endl;
		}
				sort(nearest.begin(),nearest.end(),CMP2);
		}
	}
}
void getNearest(node arr,kdnode* tree,vector<holder>& nearest,int depth){
/*
Code:
if kd is empty then set dist-sqd to in nity and exit.
1.
s := split eld of kd
2.
pivot := dom-elt eld of kd
3.
Cut hr into two sub-hyperrectangles left-hr and right-hr.
4.
The cut plane is through pivot and perpendicular to the s dimension.
target-in-left := targets pivots
5.
if target-in-left then
6.
nearer-kd := left eld of kd and nearer-hr := left-hr
6.1
further-kd := right eld of kd and further-hr := right-hr
6.2
if not target-in-left then
7.
nearer-kd := right eld of kd and nearer-hr := right-hr
7.1
further-kd := left eld of kd and further-hr := left-hr
7.2
Recursively call Nearest Neighbour with parameters
8.
(nearer-kd,target, nearer-hr,max-dist-sqd), storing the results
in nearest and dist-sqd
max-dist-sqd := minimum of max-dist-sqd and dist-sqd
9.
A nearer point could only lie in further-kd if there were some
10.
p
part of further-hr within distance max-dist-sqd of target.
if this is the case then
if (pivot ; target)2 < dist-sqd then
10.1
nearest := (pivot range-elt eld of kd)
10.1.1
dist-sqd := (pivot ; target)2
10.1.2
max-dist-sqd := dist-sqd
10.1.3
Recursively call Nearest Neighbour with parameters
10.2
(further-kd,target, further-hr,max-dist-sqd),
storing the results in temp-nearest and temp-dist-sqd
If temp-dist-sqd < dist-sqd then
10.3
nearest := temp-nearest and dist-sqd := temp-dist-sqd
10.3.1


*/
	if(tree == NULL){
		return;
	}
	if(tree->right == NULL && tree->left == NULL){
		//found a leaf
		if(arr.id!=tree->nd.id)
			addTarget(nearest,tree->nd,arr);
	}
	kdnode* nearer=NULL,*further=NULL;
	if(tree->right == NULL || (tree->left!=NULL && arr.crd[depth%2] < tree->nd.crd[depth%2])){
		nearer=tree->left;
		further=tree->right;
	}
	else
	{
		nearer=tree->right;
		further=tree->left;	
	}
	getNearest(arr,nearer,nearest,depth+1);
	
if(further!=NULL){
if(nearest.size()< 3 || (arr.crd[depth%2] - tree->nd.crd[depth%2])*(arr.crd[depth%2] - tree->nd.crd[depth%2])< nearest[2].distance)
			getNearest(arr,further,nearest,depth+1);	
	}
	
	if(arr.id!=tree->nd.id)
			addTarget(nearest,tree->nd,arr);
	
}
int main(int argc,char* argv[]){
	vector<node> arr;
	ifstream fin(argv[1]);
	int id=-1;
	int c=0;
	while(fin>>id){
	
		node temp;
		temp.id=id;
		fin>>temp.crd[0]>>temp.crd[1];
		c++;
		arr.push_back(temp);
	
	}
	kdnode* kdtree=createKDtree(arr,0);
	inorder(kdtree);
	cout<<endl;
	//cout<<"tree "<<depth(kdtree)<<" left "<<depth(kdtree->left)<<" right ";
	//cout<<depth(kdtree->right)<<"\n";
	//cout<<count(kdtree)<<" "<<count(kdtree->left)<<" "<<count(kdtree->right)<<"\n";
	//cout<<c<<"\n";
	for(int i=0;i<arr.size();i++){
		vector<holder> list;
		getNearest(arr[i],kdtree,list,0);
		cout<<arr[i].id<<" "<<list[0].id<<","<<list[1].id<<","<<list[2].id<<"\n";
		
	}	
}
