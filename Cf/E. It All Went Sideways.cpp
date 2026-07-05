#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){cin>>a[i]; }
    ll ans=0;
    vector<ll>b(n+1,0);
    vector<ll>pn(n+1);
    pn[n]=LLONG_MAX;
    ll p=a[n-1];pn[n-1]=p;
    for(int i=n-2;i>=0;i--){
        if(a[i]>p){
            b[i]=b[i+1]+a[i]-p;
        }else{
            p=a[i];
            b[i]=b[i+1];
        }
        pn[i]=p;
    }
    ans=b[0];
    for(int i=n-1;i>=1;i--){
        if(a[i]==0||(a[i]-1>=pn[i+1])){continue;}
        ll p=a[i]-1,tp=b[0];
        auto it=upper_bound(pn.begin(),pn.end(),p);
        if(it==pn.end()) tp+=i;
        else tp+=i-(it-pn.begin());
        ans=max(ans,tp);
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