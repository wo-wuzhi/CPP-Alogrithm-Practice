#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,s,res=LLONG_MAX;

ll getcost(vector<vector<ll>>&a,map<pair<ll,ll>,ll>&cost,ll t,ll ct,vector<bool>&ch){
    if(t==s){ 
        return ct;
    }
    ll res=LLONG_MAX;
    for(auto it:a[t]){
        if(ch[it]){
            ch[it]=false;
            ll tp=getcost(a,cost,it,ct+cost[{t,it}],ch);
            ch[it]=true;
            if(tp!=LLONG_MAX) res=min(res,tp);
        }
    }
    return res;
}

int main(){
    ll ans=-1;
    cin>>n>>m>>s;
    vector<vector<ll>>a(n+1,vector<ll>());
    map<pair<ll,ll>,ll>cost;
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        a[x].push_back(y);
        cin>>cost[{x,y}];
    }
    ll k;cin>>k;
    vector<ll>st(k);
    for(int i=0;i<k;i++) cin>>st[i];
    for(int i=0;i<k;i++){
        vector<bool>ch(n+1,true);
        ch[st[i]]=false;
        ll res=getcost(a,cost,st[i],0,ch);
        if(res!=LLONG_MAX)ans=max(ans,res);
    }
    cout<<ans<<endl;
}