#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,k;
    cin>>n>>k;
    pair<ll,pair<ll,ll>>a[n];
    for(ll i=0;i<n;i++){cin>>a[i].first>>a[i].second.first>>a[i].second.second;}
    ll cur=k;
    sort(a,a+n);
    for(ll i=0;i<n;i++){
        if(a[i].first>cur) break;
        cur=max(cur,a[i].second.second);
    }
    cout<<cur<<endl;
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