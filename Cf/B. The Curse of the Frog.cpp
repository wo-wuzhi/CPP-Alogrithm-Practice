#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct num{
    ll up;
    ll cnt;
    ll down;
};

bool cmp(num a,num b){
    return a.up*a.cnt-a.down<b.up*b.cnt-b.down;
}

void solve(){
    ll n,x,sum=0,ans=0;
    cin>>n>>x;
    vector<num>a;
    for(ll i=0;i<n;i++){
        num tp;
        cin>>tp.up>>tp.cnt>>tp.down;
        sum+=tp.up*(tp.cnt-1);
        if(tp.down<tp.up*tp.cnt) a.push_back(tp);
    }
    if(sum>=x){cout<<0<<endl;return;}
    else if(a.empty()){cout<<-1<<endl;return;}
    else {
        sort(a.begin(),a.end(),cmp);
        x-=sum;
        ll k=a.size();
        if(x%(a[k-1].up*a[k-1].cnt-a[k-1].down)==0) ans+=x/(a[k-1].up*a[k-1].cnt-a[k-1].down);
        else ans+=x/(a[k-1].up*a[k-1].cnt-a[k-1].down)+1;
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