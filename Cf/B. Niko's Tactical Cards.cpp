#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,ma=0,mi=0;
    cin>>n;
    vector<ll>a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++){
        ll nma=max(ma-a[i],b[i]-mi);
        ll nmi=min(mi-a[i],b[i]-ma);
        ma=nma,mi=nmi;
    }
    cout<<ma<<endl;
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