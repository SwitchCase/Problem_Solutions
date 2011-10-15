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


class P {
	public:
	P() {
		cout<<"P IS CONST "<<endl;
	}
	virtual ~P() {
		cout<<"P IS DEST "<<endl;
	}
};

class C:P {
public:
	C() {
		cout<<"C IS CONST"<<endl;
	}
	virtual ~C() {
		cout<<"C IS DEST"<<endl;
	}
};
class D:P {
public:
	D() {
		cout<<"D is CONST"<<endl;
	}
	virtual ~D() {
		cout<<"D is DEST"<<endl;
	}
};

class E:C,D {
public:
	E() {
		cout<<"E is CONST"<<endl;
	}
	virtual ~E() {
		cout<<"E is DEST"<<endl;
	}
	
};

 
int main(int argc,char** args)
{
	E *e=new E;
	delete e;
	 	
 	
}
