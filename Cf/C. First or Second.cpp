#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){cin>>a[i];}
    vector<ll>p(n+1,0);
    vector<ll>q(n+1,0);
    p[1]=a[0];
    for(int i=2;i<=n;i++) p[i]=p[i-1]+abs(a[i-1]);
    for(int i=n;i>=1;i--) q[i-1]=q[i]+a[i-1];
    ll ans=0,cur=0;
    for(int i=1;i<=n;i++){
        cur=p[i-1]-q[i];
        if(i==1)ans=cur;
        ans=max(ans,cur);
    }
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