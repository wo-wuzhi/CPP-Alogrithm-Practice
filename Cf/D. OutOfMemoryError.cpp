#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,m,h;
    cin>>n>>m>>h;
    vector<ll>a(n+1);
    for(int i=0;i<n;i++){cin>>a[i+1];}
    vector<ll>sum(n+1,0);
    set<ll>place;
    for(int i=0;i<m;i++){
        ll p,x;
        cin>>p>>x;
        sum[p]+=x;
        place.insert(p);
        if(sum[p]+a[p]>h){
            for(ll it:place){
                sum[it]=0;
            }
            place.clear();
        }
    }
    for(int i=1;i<n+1;i++) cout<<a[i]+sum[i]<<' ';
    cout<<endl;
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