#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,tp,cur;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    tp=a[0];
    cur=0;
    for(int i=1;i<n;i++){
        if(a[i]%tp==0){
            cur=gcd(cur,a[i]);
        }
    }
    if(cur==tp)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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