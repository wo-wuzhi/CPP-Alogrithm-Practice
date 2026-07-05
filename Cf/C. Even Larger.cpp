#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,ans=0;
    cin>>n;
    vector<ll>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    ll much=0;
    for(int k=1;2*k<=n;k++){
        if(k==1){
            much=max(0LL,a[2*k]-a[2*k-1]);
            ans+=much-a[2*k]+a[2*k-1];
        }else{
            ll x=min(much,a[2*k-1]);
            much=max(0LL,a[2*k]-x);
            ans+=much-a[2*k]+a[2*k-1];
        }
    }
    if(n%2==1)ans+=max(0LL,a[n]-much);
    cout<<ans<<endl;
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