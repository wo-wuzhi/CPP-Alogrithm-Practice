#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,k;
    cin>>n>>k;
    if(n==k) {cout<<0<<endl;return;}
    ll x=n,y=n,cnt=0;
    while(x>1||y>1){
        x/=2;
        y=y-y/2;
        cnt++;
        if(x==k||y==k){cout<<cnt<<endl;return;}
    }
    cout<<-1<<endl;
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