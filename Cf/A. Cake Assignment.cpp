#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll k,x;
    cin>>k>>x;
    vector<ll>ans;
    ll pre=1,a=2,m=1,n=2,kx=k;
    while(kx){
        if(kx&1==1)pre*=a;
        a*=a;
        kx>>=1;
    }
    if(x==pre){cout<<0<<endl;return;}
    if(x>pre){x=2*pre-x,m=2,n=1;}
    ll y=2*pre-x;
    for(int i=0;i<k;i++){
        if(x<pre){
            x*=2; y=2*pre-x;
            ans.push_back(m);
        }else if(x>pre){
            y*=2; x=2*pre-y;
            ans.push_back(n);
        }
    }
    cout<<ans.size()<<endl;
    reverse(ans.begin(),ans.end());
    for(auto it:ans) cout<<it<<' ';
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