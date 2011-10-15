#include <iostream>
typedef unsigned int uint;
using namespace std;

int main(){
    int tc; cin>>tc;
    for(int t=1;t<=tc;t++){
        int n; cin>>n;
        int m=1000000000,x=0,s=0,k;
        while(n--){
            cin>>k;
            x^=k; m<?=k; s+=k;
        }
        cout<<"Case #"<<t<<": ";
        if(x) cout<<"NO\n";
        else cout<<(s-m)<<"\n";
    }
}
