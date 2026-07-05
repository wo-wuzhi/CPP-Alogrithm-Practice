#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll a,b;
    cin>>a>>b;
    if((a+b)%2==0){
        if(a%2==1){
            cout<<a*b+1<<endl;
            return;
        }else{
            cout<<a*b/2+2<<endl;
            return;
        }
    }else{
        if(a%2==1){
            if((a*b/2)%2==1) cout<<-1<<endl;
            else cout<<a*b/2+2<<endl;
            return;
        }else{
            cout<<-1<<endl;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        solve();
    }
    return 0;
}