#include<iostream>
#include<cstdio>
#include<cstdlib>

//#include "test2.cpp"
using namespace std;
#define SWAP(x,y) int __=(x);(x)=(y);(y)=(__)


class Test
{
	public:
	int i;
	Test():i(0){}
	virtual int blah()
	{
		cout<<"IN TEST"<<endl;
		return 9;
	}
};

class inheritTest:Test
{
	public:
	int t;
	inheritTest():t(100){}
	int blah()
	{
		cout<<"IN inheritTEST"<<endl;
		return 10;
	}
};

int & fun2()
{
	int *p=new int(1000);
	return *p;
}

int fun3()
{

	cout<<"JAJJJAJA"<<endl;
	//return *(int*)(reinterpret_cast<void*>(cout<<"asdsd"<<endl));
	
}

int main()
{
/*
	int xxx=100;
	int yyy=-1000;
	SWAP(xxx,yyy);
	cout<<xxx<<" "<<yyy<<endl;*/
	const int *a;
	int const *b;
	int dd=0;
	int *const c=&dd;
	Test t, *pt;
	inheritTest it,*pit;
	pt = new Test;
	pit=new inheritTest;
	pt->blah();
	pit->blah();
	cout<<sizeof(Test)<<" "<<sizeof(inheritTest)<<endl;
	void* pint=*(reinterpret_cast<void**>(reinterpret_cast<int*>(pit)+2));
	pint= reinterpret_cast<void*>(&fun3);
//	pint=(reinterpret_cast<void*>(pt)+1);
	//pint=NULL;
	((Test*)pit)->blah();
	/*
	inheritTest *pit;
	pit=new inheritTest;
	pit->blah();*/
}
