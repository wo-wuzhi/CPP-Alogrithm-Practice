#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool can(ll mid,ll k,vector<ll>&a){
    ll i=1,sum=0;
    while(i<=a.size()-1&&a[i]<mid) {sum+=mid-a[i];i++;}
    if(sum<=k) return true;
    else return false;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n+1,0);
    vector<ll>b(n+1,0);
    for(ll i=0;i<n;i++){ 
        cin>>a[i+1]; 
    }
    sort(a.begin(),a.end());
    for(ll i=0;i<n;i++){ 
        b[i+1]=b[i]+a[i+1];
    }
    ll p=1,l=a[1],r=a[n],mi=0;
    while(l<=r){
        ll mid=(l+r)/2;
        if(can(mid,k,a)){
            mi=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    ll i=1;
    while(i<n&&a[i]<=mi) i++;
    ll ans=(mi-1)*n+1+k-(mi*(i-1)-b[i-1]);
    if(i<n||(i==n&&a[i]!=mi)) ans+=n-i+1;
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