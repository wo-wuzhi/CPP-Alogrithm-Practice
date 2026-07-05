#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll m,n,x,sum=0,tp=0;
    cin>>m>>n>>x;
    vector<ll>a(m);
    for(int i=0;i<m;i++){cin>>a[i];}
    for(int i=m-1;i>=0;i--){
        sum+=a[i];
        if(sum>=x){cout<<n*m-(m-1-i)<<endl;return;}
    }
    if(n*sum<x){cout<<0<<endl;return;}
    ll tpx=x%sum,tpn=n-x/sum,temp=0;
    if(tpx==0) temp=1;
    for(int i=m-1;i>=0;i--){
        tp+=a[i];
        if(tp>=tpx){cout<<tpn*m-(m-1-i)+temp<<endl;return;}
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