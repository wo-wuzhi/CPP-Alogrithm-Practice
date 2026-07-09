#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll x,k,y;
    cin>>x>>y>>k;
    x++;
    k--;
    while(x%y==0) x/=y;
    while(k>=y-x%y&&x!=1){
        ll tp=y-x%y;
        x+=tp;
        k-=tp;
        while(x%y==0) x/=y;
    }
    if(k>=y-1){
        cout<<1+k%(y-1)<<endl;
    }else{
        cout<<x+k<<endl;
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