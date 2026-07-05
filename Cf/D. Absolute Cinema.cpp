#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,tp=0;
    cin>>n;
    vector<ll>a(n);
    vector<ll>ans(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int sum=(a[0]+a[n-1])/(n-1);
    for(int i=0;i<n-1;i++){
        ans[i]=(sum-(a[i]-a[i+1])-2*tp)/2;
        tp+=ans[i];
    }
    ans[n-1]=sum-tp;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        solve();
    }
}