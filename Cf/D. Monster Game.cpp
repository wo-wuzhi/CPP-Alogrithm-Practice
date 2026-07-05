#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,ans=0;
    cin>>n;
    set<ll>num;
    vector<ll>a(n);
    vector<ll>b(n);
    vector<ll>sumb(n+1);
    for(int i=0;i<n;i++){cin>>a[i];num.insert(a[i]);}
    for(int j=0;j<n;j++){cin>>b[j];sumb[j+1]=sumb[j]+b[j];}
    sort(a.begin(),a.end());
    for(ll x:num){
        auto it=lower_bound(a.begin(),a.end(),x);
        ll y=n-(it-a.begin());
        if(y>=sumb[n]) ans=max(ans,x*sumb[n]);
        else{
            auto res=lower_bound(sumb.begin(),sumb.end(),y);
            if(sumb[res-sumb.begin()]>y) res--;
            if(res!=sumb.begin())
            ans=max(ans,x*(res-sumb.begin()));
        }
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