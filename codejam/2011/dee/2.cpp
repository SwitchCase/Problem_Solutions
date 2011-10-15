#include <iostream>
typedef unsigned int uint;
using namespace std;

int main(){
    int T; cin>>T;
    for(int t=1;t<=T;t++){
        int comb[256][256]={0};
        int oops[256][256]={0};
        int C; cin>>C;
        string str;
        while(C--){
            cin>>str;
            comb[(uint)str[0]][(uint)str[1]] = str[2];
            comb[(uint)str[1]][(uint)str[0]] = str[2];
        }
        cin>>C;
        while(C--){
            cin>>str;
            oops[(uint)str[0]][(uint)str[1]] = 1;
            oops[(uint)str[1]][(uint)str[0]] = 1;
        }
        int sz;
        cin>>sz>>str;
        string ans="";
        for(int i=0;i<sz;i++){
            if(ans != ""){
                int a = comb[(uint)str[i]][(uint)ans[ans.size()-1]];
                if(a) ans[ans.size()-1] = char(a);
                else{
                    for(int j=0;j<ans.size();j++)
                        if(oops[(uint)str[i]][(uint)ans[j]]){
                            ans = ""; break;
                        }
                    if(ans!="") ans += str[i];
                }
            } else {
                ans += str[i];
            }
            //cout<<"(debug) "<<ans<<"\n";
        }
        cout<<"Case #"<<t<<": [";
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i+1!=ans.size()) cout<<", ";
        }
        cout<<"]\n";
    }
}
