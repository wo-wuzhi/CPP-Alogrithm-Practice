#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
    ll n,res=0;
    cin>>n;
    vector<ll>a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            res=max(res,a[i]^a[j]);
        }
    }
    cout<<res<<endl;
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