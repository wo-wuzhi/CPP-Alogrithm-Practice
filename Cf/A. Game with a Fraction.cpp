#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll x,y;
    cin>>x>>y;
    if(y<3||x<2){cout<<"Alice"<<endl;return;}
    ll m=y/3,n; m*=2;
    if(m>x){
        n=x/2; n*=3;
    }else{
        n=m/2; n*=3;
    }
    ll cnt=x+y-m-n,tp=3*x-2*y;
    if((tp<0||x-tp<2||y-tp<3)) {cout<<"Alice"<<endl;return;}
    else {cout<<"Bob"<<endl;return;}
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