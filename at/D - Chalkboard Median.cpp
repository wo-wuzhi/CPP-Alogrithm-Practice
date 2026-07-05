#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll x,q;
    cin>>x>>q;
    priority_queue<ll,vector<ll>,greater<ll>>r;
    priority_queue<ll>l;
    l.push(x);
    for(ll i=0;i<q;i++){
        ll m,n,ans;
        cin>>m>>n;
        l.push(m),l.push(n);
        while(l.size()>r.size()+1){
            ll tp=l.top();
            l.pop();
            r.push(tp);
        }
        while(l.top()>r.top()){
            ll a=l.top(),b=r.top();
            l.pop(),r.pop();
            l.push(b),r.push(a);
        }
        ans=l.top();
        cout<<ans<<endl;
    }
    
    return 0;
}