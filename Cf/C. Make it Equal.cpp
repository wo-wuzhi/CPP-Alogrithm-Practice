#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,k;
    cin>>n>>k;
    map<ll,ll>a;
    vector<ll>b(n);
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        a[x%k]++;
        a[abs(x%k-k)]++;
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        ll tp=b[i]%k;
        if(a[tp]>0){
            a[tp]--;
            a[abs(tp-k)]--;
        }else{
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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