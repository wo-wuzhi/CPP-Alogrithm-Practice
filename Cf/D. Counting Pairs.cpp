#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,x,y,cnt=0,sum=0;
    cin>>n>>x>>y;
    vector<ll>a(n);
    for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
    sort(a.begin(),a.end());
    for(ll i=0;i<n;i++){
        auto it1=upper_bound(a.begin()+i+1,a.end(),sum-a[i]-x);
        auto it2=lower_bound(a.begin()+i+1,a.end(),sum-a[i]-y);
        cnt+=it1-it2;
    }
    cout<<cnt<<endl;
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