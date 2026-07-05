#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,k,cnto=0;
    cin>>n>>k;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]+=(a[i]%(k+1))*k;
    }
    for(auto it:a) cout<<it<<' ';
    cout<<endl;
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